#Name: Ghazi Najeeb Al-Abbar
#ID: 2181148914
#Lab 07
#Lab7Q2.py

#Checks if the matrix is singular (returns true if the determinant is 0. Otherwise, it returns false)
def isSingular(Mat):

    if (Mat[0][0] * Mat[1][1]) - (Mat[1][0] * Mat[0][1]) == 0:

        return True;
    
    return False;

'''
    Function that solves a 2x2 matrix and returns the solution vector
    suppose the matrix is:
                            [a b | e]
                            [c d | f] 
'''
def Solve(Mat, sol):

    #The case where a = 0
    if Mat[0][0] == 0:

        '''
            [0 b | e]       [c d | f]
            [c d | f] =>    [0 b | e]
        '''
        temp = Mat[0];
        Mat[0] = Mat[1];
        Mat[1] = temp;

        temp = sol[0];
        sol[0] = sol[1];
        sol[1] = temp;

        '''
            [c d | f]       [1 (d/c) | (f/c)]
            [0 b | e] =>    [0   b   |   e  ]
        '''

        Mat[0][1] /= Mat[0][0];
        sol[0] /= Mat[0][0];
        Mat[0][0] = 1;

        '''
            [1 (d/c) | (f/c)]       [1 (d/c) | (f/c)]
            [0   b   |   e  ] =>    [0   1   | (e/b)]
        '''
        sol[1] /= Mat[1][1];
        Mat[1][1] = 1;

        '''
            [1 (d/c) | (f/c)]       [1 0 | (f/c) - (d/c)(e/b)]
            [0   1   | (e/b)] =>    [0 1 |      (e/b)        ]
        '''
        sol[0] += -Mat[0][1] * sol[1];
        Mat[0][1] = 0;

    #The case where c = 0:
    elif Mat[1][0] == 0:

        '''
            [a b | e]       [1 (b/a) | (e/a)]
            [0 d | f] =>    [0   d   |   f  ]
        '''
        Mat[0][1] /= Mat[0][0];
        sol[0] /= Mat[0][0];
        Mat[0][0] = 1;

        '''
            [1 (b/a) | (e/a)]       [1 (b/a) | (e/a)]
            [0   d   |   f  ] =>    [0   1   | (f/d)]
        '''
        sol[1] /= Mat[1][1];
        Mat[1][1] = 1;

        '''
            [1 (b/a) | (e/a)]       [1 0 | (e/a) - (b/a)(f/d)]
            [0   1   | (f/d)] =>    [0 1 |      (f/d)        ]
        '''
        sol[0] += -Mat[0][1] * sol[1];
        Mat[0][1] = 0;

    #The case where the matrix stays the same
    else:

        '''
            [a b | e]       [1 (b/a) | (e/a)]
            [c d | f] =>    [c   d   |   f  ]
        '''
        Mat[0][1] /= Mat[0][0];
        sol[0] /= Mat[0][0];
        Mat[0][0] = 1;

        '''
            [1 (b/a) | (e/a)]       [1    (b/a)   |    (e/a)  ]
            [c   d   |   f  ] =>    [0 d - c(b/a) | f - c(e/a)]
        '''
        Mat[1][1] += -Mat[1][0] * Mat[0][1];
        sol[1] += -Mat[1][0] * sol[0];
        Mat[1][0] = 0;

        '''
            [1    (b/a)   |    (e/a)  ]     [1 (b/a) |            (e/a)           ]
            [0 d - c(b/a) | f - c(e/a)] =>  [0   1   | (f - c(e/a)) / (d - c(b/a))]
        '''
        sol[1] /= Mat[1][1];
        Mat[1][1] = 1;

        '''
            [1 (b/a) |            (e/a)           ]     [1 0 | (e/a) - (b/a)((f - c(e/a)) / (d - c(b/a)))]
            [0   1   | (f - c(e/a)) / (d - c(b/a))] =>  [0 1 |        (f - c(e/a)) / (d - c(b/a))        ]
        '''
        sol[0] += -Mat[0][1] * sol[1];
        Mat[0][1] = 0;

    return sol;

#Beginning of main
def main():

    Matrix = [];
    print("Enter the elements for your square matrix: ");

    row = input("Enter the elements for the first row: ").split();
    Matrix.append([float(x) for x in row]);

    row = input("Enter the elements for the second row: ").split();
    Matrix.append([float(x) for x in row]);

    sol = input("Enter the solution vector: ").split();
    sol = [float(x) for x in sol];

    if isSingular(Matrix):

        print("No unique solution.\n");
        return;
    
    Vec = Solve(Matrix, sol);

    print("[x y] = [", Vec[0], " ", Vec[1], "]");
#End of main

#Calling main
main();