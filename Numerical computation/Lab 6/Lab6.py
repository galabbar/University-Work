#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914

#X_n+1 = X_n - (f(X_n)/f'(X_n))
#X_0 = 1 + ((X-1)/n) 

def nth_root(x, n, e = 0.05, MAXIT = 50, init = 1):

    X_old = 1 + ((x - 1) / n);
    itr = 0;

    while abs(X_old**n - x) > e and itr < MAXIT:

        Num = X_old**n - x;
        Denum = n * X_old**(n - 1);

        X_new = X_old - Num / Denum;
        X_old = X_new;

        itr += 1;

    return X_old;


print(nth_root(17, 5));