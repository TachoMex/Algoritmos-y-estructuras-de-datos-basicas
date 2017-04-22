
# Numbers

Positive Numbers:

$$
\mathbb{N} = \{1, 2, 3, 4 ...\}
$$

Integer Number:

$$
\mathbb{Z} = \{0, 1, -1, 2, -2, ...\}
$$

-Divisibility

If $a, b \in \mathbb{Z}$ then for some $c \in \mathbb{N}$, we say $b$ divides $a$ if $a = bc$, we write it as $b | a$


# Sieve of Erathostenes
- Can find all prime numbers between 1 and $N$
- You only need an array of bools to mark numbers as prime/composed.
- Mark $0$ and $1$ as composed
- Iterate the array and when you find a number that is not marked as composite
  then means that number is prime.
- Mark all the multiples of the prime number as composite.
- At the end, all the numbers that were not marked are the primes.

```c++
const int N = 1000;
bool sieve[N];

void compute_sieve(){
  memset(sieve, 1, sizeof(sieve));
  // mark 0 and 1 as composed
  // you can declare the array as global and they will be set to false,
  // you only will need to inver the logic here.
  sieve[0] = sieve[1] = false;
  // an optimization can be done here, but first read the next one.
  // As you saw, the first number that is marked is i^2,
  // then when you get above the sqrt(N), all the composite numbers
  // will be marked because i^2 > n for i > sqrt(N).
  for(int i = 0; i < N; i++){
    if(sieve[i]){
      // another optimization can be done by initializing
      // j = i * i, but just take care with overflow.
      // proof:
      // Supose there exist a number k < i * i and k = i^2
      // There must be a prime number p | l
      // and by transition, p < l < k < i^2
      // Since p is a prime number and p < i, al multyples of p
      // must have been marked before, and there is a contradiction.
      for(int j = i + i; j < N; j++){
        sieve[j] = false;
      }
    }
  }
}

```

# Fundamental theorem of arithmetic
- It says that for any Positive number there exists a way to express the number
  as a serie of products of prime numbers and that sequence is unique despite the order.

For example:
  - $100 = 5^2 \times 2^2$
  - $42 = 2 \times 3 \times 7$

The primary point is to learn how to compute the prime factors _fast_.
```c++
vector<int> factorize(int n, const vector<int>& primes){
  // We have calculated the primes using sieve and stored them on primes vector.
  int i = 0;
  vector<int> factors;
  // if n is 1, then we are done.
  // if the current prime squared is bigger than n, means it is prime
  // or if the sieve[n] is marked as prime, also means the same as the above.
  // the second validation is useful when the limit of N is a large number and
  // we only calculate the primes until the square of the maximum N.
  while(n != 1 && primes[i] * primes[i] <= n && !sieve[n]){
    // if primes[i] is a factor, store it and divide N.
    // this causes N to shrink, and eventually it will be a prime or 1
    while(n % primes[i] == 0){
      factors.push_back(primes[i]);
      n /= primes[i];
    }
    i++;
  }
  // Now, we only validate if n is 1, if it is not, then N is the last factor
  if(n != 1){
    factors.push_back(n);
  }
  return factors;
}
```

# GCD y LCM
- Greatest Common Multiple
  - The biggest integer that divides a set of numbers
  - Given $a, b \in \mathbb{Z}$, there is a number $d \in \mathbb{Z}$ that satisfies that
    $d | a$ and $d|b$, and $d$ is maximum.
  - There is always a GCD for any pair of positive integers
- Lowest Common Divisor
  - The lowest number that is a multiple of a set of numbers.
  - Given $a, b \in \mathbb{Z}$, there is a number $d \in \mathbb{Z}$ that satisfies that $a|d$ and $b|d$.
  - Also, there is always a LCM for any pair of positive integers.
- $GCD(a, b) = GCD(b, a)$
- $GCD(a, 0) = a$
- $GCD(a, b) = GCD(b,a\mod b)$
- $ab = GCD(a, b) \times LCM(a, b)$

# Euclid's algorithm
- It comes from the property:
- $GCD(a, 0) = a$
- $GCD(a, b) = GCD(b, a\mod b)$

```c++
//one line recursive implementation
int gcd(int a, int b){
  return (b == 0 ? a : gcd(b, a % b));
}

//iterative implementation
int gcd(int a, int b){
  while(b != 0){
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm(int a, int b){
  // first divide to avoid overflow
  return a / gcd(a, b) * b;
}
```
# $\varphi$ function
- $\varphi(n)$ is a function that counts the number of coprimes, relative primes between 1 and n.
- A relative prime of $n$ is a number p that satisfies that $gcd(n, p) = 1$
- $\varphi(p) = p - 1$ if $p \in \mathbb{P}$
- $\varphi(pq) = \varphi(p) \varphi(q) = (p - 1)(q - 1)$ if $p, q \in \mathbb{P}$
- $\varphi(p^n) = (p - 1) p ^ {n - 1}$
- Given the prime representation of a number, calculate the $\varphi$ function is easy.

# Modular arithmetics
- $a \equiv b \mod n$ if $a = nk + b$, for $a, b, n, k \in \mathbb{Z}$ (1)
- $(1) \implies a + c \equiv b + c \mod n$
- $(1) \implies ac \equiv bc \mod n$
- $k \times k^{-1} \equiv 1 \mod n$
# Fermat's little theorem
- $a^p \equiv a \mod p$ if $p \in \mathbb{P}$ (1)
- $(1) \implies a^{(p-1)} \equiv 1 \mod p$ (2)
- $(2) \implies a \times a^{(p - 2)} \equiv a \times a^{-1} \equiv 1 \mod p$ (3)
- $(3) \implies a^{-1} \equiv a^{(p-2)}$

# Euler's theorem
- Fermat's little theorem can be derived from Euler's theorem.
- $a^{\varphi(n)} \equiv 1 \mod n$

# Fast exponentiation algorithm
- Given $a, b \in \mathbb{Z}^+$, find $a^b$ in the fastest way possible.
- $a \times a = a^2$
- $a^n \times a^n = a^{2n}$
- $a^{2n} = a^n \times a^n$

```c++
int pow(int a, int b, int c){
  if(b == 0){
    return 1;
  }else if(b == 1){
    return a;
  }else{
    int t = pow(a, b/2, c);
    t = t * t % c * pow(a, b % 2, c) % c;
    return t;
  }
}
```

# diophantine equations

# Extended euclid's algorithm
# RSA
# Pell's equation
# Online practice!
- https://omegaup.com/arena/problem/Agente-A-El-Heroe-Nacional
- https://omegaup.com/arena/problem/subprimos
- https://omegaup.com/arena/problem/subprimos
- https://omegaup.com/arena/problem/Divisores-Iguales
- https://omegaup.com/arena/problem/Numeros-Libres
- https://omegaup.com/arena/problem/transmission
- https://omegaup.com/arena/problem/multinverse
- https://omegaup.com/arena/problem/goldbach
- https://omegaup.com/arena/problem/fencepaintinggame
- https://omegaup.com/arena/problem/Divisores-de-N
- CUCEI 2016: http://redprogramacioncompetitiva.com/forum/viewforum.php?f=1001&sid=c953469a850b2243e5fa44b241aca70e
  - King of the bar
  - Factorial Divisors
