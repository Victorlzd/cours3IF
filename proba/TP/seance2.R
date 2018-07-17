Bernoulli <- function(p)
{
  x <- runif(1)
  if(x<=p)
  {
    return(1)
  }
  else
  {
    return(0)
  }
}

Binomiale <- function(n,p)
{
  somme = 0;
  for(i in 1:n)
  {
    somme <- somme + Bernoulli(p)
  }
  return(somme)
}

grapheBinomiale <- function(nBinom,p,nbTirage)
{
  binomiale <- c()
  for(i in 1:nbTirage)
  {
    binomiale <- c(binomiale,Binomiale(nBinom,p))
  }
  plot(table(binomiale))
}

LoiNormale01 <- function()
{
  u <- runif(1)
  v <- runif(1)
  return(sqrt(-log(u))*cos(2*pi*v))
}

LoiNormale <- function(n,p)
{
  return(n*p+n*p*(1-p)*LoiNormale01())
}

grapheBinNormal <- function(n,p, nbTirage)
{
  par(mfrow=c(1,2))
  grapheBinomiale(n,p,nbTirage)
  
  normal <- c()
  for(i in 1:nbTirage)
  {
    normal <- c(normal,LoiNormale(n,p))
  }
  hist(normal)
}


FileMM1 <- function(lambda,mu,D)
{
  nbArrivee<-0
  d <- 0
  depart <- c()
  arrivee <- c()
  
  d<-rexp(1,lambda)
  while(d<D)
  {
    nbArrivee <- nbArrivee+1
    arrivee <- c(arrivee,d)
    d<- d+rexp(1,lambda)
  }
  
  if(nbArrivee>0)
  {
    nDepart <- 1
    d<-arrivee[nDepart]
    d<- d+rexp(1,mu)
    
    while(d<D && nDepart<=nbArrivee)
    {
      depart <- c(depart,d)
      nDepart <- nDepart+1
      if(nDepart<=nbArrivee)
      {
        if(d<arrivee[nDepart])
        {
          d<-arrivee[nDepart]
        }
      }
      d<- d+rexp(1,mu)
    }
  }
  return(list(arrive=arrivee,depart=depart))
}

Modelisation <- function(liste,max)
{
  arrive <- c(liste$arrive,max)
  depart <- c(liste$depart,max)
  nArrivee <- length(arrive)
  nDepart <- length(depart)
  if(nArrivee > 1)
  {
    currentArrivee <- 1
    currentDepart <- 1
    
    vecN <- c()
    vecT <- c()
    n<-0
    
    while (currentArrivee<nArrivee || currentDepart<nDepart) {
      if(arrive[currentArrivee] < depart[currentDepart])
      {
        n<-n+1
        vecT <- c(vecT,arrive[currentArrivee])
        currentArrivee <- currentArrivee+1
      }
      else
      {
        n<-n-1
        vecT <- c(vecT,depart[currentDepart])
        currentDepart <- currentDepart+1
      }
      vecN <- c(vecN,n)
    }
    #plot(vecN)
    plot(vecT, vecN, type = "S", main='RANDU')
    #return(vec)
  }
  else
  {
    print(liste)
    print("Aucune arrivée")
  }
}


MoyenneClientReste <- function(lambda, mu, D, N)
{
  vec <- c()
  for (i in 1:N) {
    liste <- FileMM1(lambda, mu, D)
    n <- length(liste$arrive)-length(liste$depart)
    vec <- c(vec,n)
  }
  return(mean(vec))
}

MoyenneTempsPasse <- function(lambda, mu, D, N)
{
  vec <- c()
  for (i in 1:N) {
    liste <- FileMM1(lambda, mu, D)
    for (j in 1:length(liste$depart)) {
      n <- liste$depart[j] - liste$arrive[j]
      vec <- c(vec,n)
    }
    
  }
  return(mean(vec))
}

VerifFormLittle <- function(lambda,mu,D,N)
{
  moyClientRestant <- MoyenneClientReste(lambda,mu,D,N)
  moyTempsPasse <- MoyenneTempsPasse(lambda,mu,D,N)
  print("Moyenne des Clients restants : E(N)")
  print(moyClientRestant)
  print("Moyenne du temps passés dans la file : E(W)")
  print(moyTempsPasse)
  print("Moyenne du temps passés fois lambda : lambda*E(W)")
  print(lambda*moyTempsPasse)
}
  