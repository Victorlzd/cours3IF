MersenneTwister <- function(n,p=1,graine)
{
  set.seed(graine,kind='Mersenne-Twister')
  x <- sample.int(2^32-1,n*p)
  x <- matrix(x,nrow=n,ncol=p)
  return(list(x=x,s=x[n]))
}


Sobol <- function(n,p) 
{
  return(round(sobol(n,p)*(2^31-1)))
}


binary <- function(x)
{
  if((x<2^31)&(x>0))
    return( as.integer(rev(intToBits(as.integer(x)))) )
  else{
    if((x<2^32)&(x>0))
      return( c(1,binary(x-2^31)[2:32]) )
    else{
      cat('Erreur dans binary : le nombre etudie n est pas un entier positif en 32 bits.\n')
      return(c())
    }
  }
}

GenCongruenceLin <- function(a,b,m,graine,p=1)
{
  x <- graine
  vect <- c()
  for(i in 1:p)
  {
    x <- (a*x+b)%%m
    vect<- c(vect,x) 
  }
  return(vect)
}

RANDU <- function(graine,p=1)
{
  return(GenCongruenceLin(65539,0,2^31,graine,p))
}

StandardMinimal <- function(graine,p=1)
{
  return(GenCongruenceLin(16807,0,2^31-1,graine,p))
}

