# au prealable, vous devez executer l'instruction suivante
# install.packages('randtoolbox')

library(randtoolbox)
source('generateurs.R')

sMT <- 2504
Nsimu <- 1000
Nrepet <- 20


############################################################
##  Section 2
############################################################

graphe <- function()
{
  sob <- Sobol(Nsimu,Nrepet)
  mt <- MersenneTwister(Nsimu,Nrepet,sMT)$x
  randu <- RANDU(sMT,Nsimu)
  stdMin <- StandardMinimal(sMT,Nsimu)
  
  par(mfrow=c(1,2))
  hist(mt[,1],xlab='',main='Mersenne Twister')
  hist(sob[,1],xlab='',main='Sobol')
  hist(randu,xlab='',main='RANDU')
  hist(stdMin,xlab='',main='Std Min')
  
  
  
  par(mfrow=c(1,2))
  plot(mt[1:(Nsimu-1),1],mt[2:Nsimu,1],xlab='dimension 1', ylab='dimension 2', main='Mersenne Twister')
  plot(sob[1:(Nsimu-1),1],sob[2:Nsimu,1],xlab='dimension 1', ylab='dimension 2', main='Sobol')
  plot(randu[1:(Nsimu-1)], randu[2:Nsimu],main='RANDU')
  plot(stdMin[1:(Nsimu-1)], stdMin[2:Nsimu],main='Std Min')
}

binaryVectToMatrix <-function(vect)
{
  m <- c()
  n <- length(vect)
  for(i in 1:n)
  {
    m<-cbind(m,binary(vect[i]))
  }
  return(m)
}

MatrixToVect <- function(m,nb)
{
  x<-c()
  n<-dim(m)[2]
  for(i in 1:n)
  {
    x<-c(x,m[(33-nb):32,])
  }
  return(x)
}

calculSn <-function(m,nb)
{
  m <- 2*m-1
  x<-sum(m[(33-nb):32,])
  return(x)
}

Frequency <- function(x,nb=32)
{
  Sn <- calculSn(binaryVectToMatrix(x),nb)
  Sobs <- abs(Sn)/sqrt(nb*length(x))
  p <- 2*(1-pnorm(Sobs))
  return(p)
}

TestFrequency <- function(nbSerie)
{
  pSobol <- Frequency(Sobol(Nsimu,1),10)
  vecMt <- c()
  vecRandu <- c()
  vecStdMin <- c()
  
  for (i in 1:nbSerie) {
    seed <- sample.int(100000,1)
    
    
    pMt <- Frequency(MersenneTwister(Nsimu,1,seed)$x,10)
    vecMt <- c(vecMt,pMt)
    
    pRandu <- Frequency(RANDU(seed,Nsimu),10)
    vecRandu <- c(vecRandu,pRandu)
    
    pStdMin <- Frequency(StandardMinimal(seed,Nsimu),10)
    vecStdMin <- c(vecStdMin,pStdMin)
  }
  
  decileSobol <- pSobol
  decileMt <- quantile(vecMt, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  decileRandu <- quantile(vecRandu, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  decileStdMin <- quantile(vecStdMin, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  
  moyenneSobol <- pSobol
  moyenneMt <- mean(vecMt)
  moyenneRandu <- mean(vecRandu)
  moyenneStdMin <- mean(vecStdMin)
  
  tableau <- data.frame(moyenne = c(moyenneSobol, moyenneMt, moyenneRandu, moyenneStdMin), PremDecile = c(decileSobol,decileMt,decileRandu,decileStdMin), row.names = c("Sobol", "Mersienne-Twister","RANDU","Standard Min"))
  tableau <- round(tableau, 3)*100
  print(tableau, digits = 3)  
}

PreTestRun <- function(vect)
{
  n <- sum(vect)
  N <- length(vect)
  if(abs(n/N-0.5)>=2/sqrt(N))
  {
    return(0)
  }
  else
  {
    return(1)
  }
}

CalculVn <- function(vect)
{
  Vn <- 1
  N <- length(vect)
  for (i in 1:(N-1)) 
  {
    
    if(vect[i]==vect[i+1])
    {
      r <- 1
    }
    else
    {
      r <- 0
    }
    Vn <- Vn + r
  }
  return(Vn)
}

CalculPvaleurRun <- function(vect)
{
  Vn <- CalculVn(vect)
  N <- length(vect)
  pi <- sum(vect)/N
  num <- abs(Vn-2*N*pi*(1-pi))
  denom <- 2*pi*(1-pi)*sqrt(N)
  Pvaleur <- 2*(1-pnorm(num/denom))
  return(Pvaleur)
}

TestCompletRun <- function(alea)
{
  vectBin <- MatrixToVect(binaryVectToMatrix(alea),10)
  if(PreTestRun(vectBin)==0)
  {
    return(0)
  }
  else
  {
    return(CalculPvaleurRun(vectBin))
  }
}

TestDesRuns <- function(nbSerie)
{
  aleaSobol <- Sobol(Nsimu,1)
  pSobol <- TestCompletRun(aleaSobol)
  
  vecMt <- c()
  vecRandu <- c()
  vecStdMin <- c()
  
  for (i in 1:nbSerie) {
    seed <- sample.int(100000,1)
    
    aleaMt <- MersenneTwister(Nsimu,1,seed)$x
    pMt <- TestCompletRun(aleaMt)
    vecMt <- c(vecMt,pMt)
    
    aleaRandu <- RANDU(seed,Nsimu)
    pRandu <- TestCompletRun(aleaRandu)
    vecRandu <- c(vecRandu,pRandu)
    
    aleaStdMin <- StandardMinimal(seed,Nsimu)
    pStdMin <- TestCompletRun(aleaStdMin)
    vecStdMin <- c(vecStdMin,pStdMin)
  }
  
  decileSobol <- pSobol
  decileMt <- quantile(vecMt, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  decileRandu <- quantile(vecRandu, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  decileStdMin <- quantile(vecStdMin, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  
  moyenneSobol <- pSobol
  moyenneMt <- mean(vecMt)
  moyenneRandu <- mean(vecRandu)
  moyenneStdMin <- mean(vecStdMin)
  
  tableau <- data.frame(moyenne = c(moyenneSobol, moyenneMt, moyenneRandu, moyenneStdMin), PremDecile = c(decileSobol,decileMt,decileRandu,decileStdMin), row.names = c("Sobol", "Mersienne-Twister","RANDU","Standard Min"))
  tableau <- round(tableau, 3)*100
  print(tableau, digits = 3)
}

Ordre <- function(vect)
{
  return(order.test(vect, d=4, echo=FALSE)$p.value)
}

TestOrdre <- function(nbSerie)
{
  aleaSobol <- Sobol(Nsimu,1)
  pSobol <- Ordre(aleaSobol)
  
  vecMt <- c()
  vecRandu <- c()
  vecStdMin <- c()
  
  for (i in 1:nbSerie) {
    seed <- sample.int(100000,1)
    
    aleaMt <- MersenneTwister(Nsimu,1,seed)$x[,1]
    pMt <- Ordre(aleaMt)
    vecMt <- c(vecMt,pMt)
    
    aleaRandu <- RANDU(seed,Nsimu)
    pRandu <- Ordre(aleaRandu)
    vecRandu <- c(vecRandu,pRandu)
    
    aleaStdMin <- StandardMinimal(seed,Nsimu)
    pStdMin <- Ordre(aleaStdMin)
    vecStdMin <- c(vecStdMin,pStdMin)
  }
  
  decileSobol <- pSobol
  decileMt <- quantile(vecMt, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  decileRandu <- quantile(vecRandu, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  decileStdMin <- quantile(vecStdMin, probs=seq(0, 1, 0.1),TRUE,FALSE)[2]
  
  moyenneSobol <- pSobol
  moyenneMt <- mean(vecMt)
  moyenneRandu <- mean(vecRandu)
  moyenneStdMin <- mean(vecStdMin)
  
  tableau <- data.frame(moyenne = c(moyenneSobol, moyenneMt, moyenneRandu, moyenneStdMin), PremDecile = c(decileSobol,decileMt,decileRandu,decileStdMin), row.names = c("Sobol", "Mersienne-Twister","RANDU","Standard Min"))
  tableau <- round(tableau, 3)*100
  print(tableau, digits = 3)  
}