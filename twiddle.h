float kosini[16][16]={
1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 1.000000 , 
1.000000 , 0.923880 , 0.707107 , 0.382683 , 0.000000 , -0.382683 , -0.707107 , -0.923880 , -1.000000 , -0.923880 , -0.707107 , -0.382683 , -0.000000 , 0.382683 , 0.707107 , 0.923880 , 
1.000000 , 0.707107 , 0.000000 , -0.707107 , -1.000000 , -0.707107 , -0.000000 , 0.707107 , 1.000000 , 0.707107 , 0.000000 , -0.707107 , -1.000000 , -0.707107 , -0.000000 , 0.707107 , 
1.000000 , 0.382683 , -0.707107 , -0.923880 , -0.000000 , 0.923880 , 0.707107 , -0.382683 , -1.000000 , -0.382683 , 0.707107 , 0.923880 , 0.000000 , -0.923880 , -0.707107 , 0.382683 , 
1.000000 , 0.000000 , -1.000000 , -0.000000 , 1.000000 , 0.000000 , -1.000000 , -0.000000 , 1.000000 , 0.000000 , -1.000000 , -0.000000 , 1.000000 , -0.000000 , -1.000000 , -0.000000 , 
1.000000 , -0.382683 , -0.707107 , 0.923880 , 0.000000 , -0.923880 , 0.707107 , 0.382683 , -1.000000 , 0.382683 , 0.707107 , -0.923880 , -0.000000 , 0.923880 , -0.707107 , -0.382683 , 
1.000000 , -0.707107 , -0.000000 , 0.707107 , -1.000000 , 0.707107 , 0.000000 , -0.707107 , 1.000000 , -0.707107 , -0.000000 , 0.707107 , -1.000000 , 0.707107 , -0.000000 , -0.707107 , 
1.000000 , -0.923880 , 0.707107 , -0.382683 , -0.000000 , 0.382683 , -0.707107 , 0.923880 , -1.000000 , 0.923880 , -0.707107 , 0.382683 , -0.000000 , -0.382683 , 0.707107 , -0.923880 , 
1.000000 , -1.000000 , 1.000000 , -1.000000 , 1.000000 , -1.000000 , 1.000000 , -1.000000 , 1.000000 , -1.000000 , 1.000000 , -1.000000 , 1.000000 , -1.000000 , 1.000000 , -1.000000 , 
1.000000 , -0.923880 , 0.707107 , -0.382683 , 0.000000 , 0.382683 , -0.707107 , 0.923880 , -1.000000 , 0.923880 , -0.707107 , 0.382683 , -0.000000 , -0.382683 , 0.707107 , -0.923880 , 
1.000000 , -0.707107 , 0.000000 , 0.707107 , -1.000000 , 0.707107 , -0.000000 , -0.707107 , 1.000000 , -0.707107 , -0.000000 , 0.707107 , -1.000000 , 0.707107 , -0.000000 , -0.707107 , 
1.000000 , -0.382683 , -0.707107 , 0.923880 , -0.000000 , -0.923880 , 0.707107 , 0.382683 , -1.000000 , 0.382683 , 0.707107 , -0.923880 , 0.000000 , 0.923880 , -0.707107 , -0.382683 , 
1.000000 , -0.000000 , -1.000000 , 0.000000 , 1.000000 , -0.000000 , -1.000000 , -0.000000 , 1.000000 , -0.000000 , -1.000000 , 0.000000 , 1.000000 , -0.000000 , -1.000000 , 0.000000 , 
1.000000 , 0.382683 , -0.707107 , -0.923880 , -0.000000 , 0.923880 , 0.707107 , -0.382683 , -1.000000 , -0.382683 , 0.707107 , 0.923880 , 0.000000 , -0.923880 , -0.707107 , 0.382683 , 
1.000000 , 0.707107 , -0.000000 , -0.707107 , -1.000000 , -0.707107 , -0.000000 , 0.707107 , 1.000000 , 0.707107 , -0.000000 , -0.707107 , -1.000000 , -0.707107 , 0.000000 , 0.707107 , 
1.000000 , 0.923880 , 0.707107 , 0.382683 , -0.000000 , -0.382683 , -0.707107 , -0.923880 , -1.000000 , -0.923880 , -0.707107 , -0.382683 , 0.000000 , 0.382683 , 0.707107 , 0.923880};
float sini[16][16]={
0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 
0.000000 , -0.382683 , -0.707107 , -0.923880 , -1.000000 , -0.923880 , -0.707107 , -0.382683 , -0.000000 , 0.382683 , 0.707107 , 0.923880 , 1.000000 , 0.923880 , 0.707107 , 0.382683 , 
0.000000 , -0.707107 , -1.000000 , -0.707107 , -0.000000 , 0.707107 , 1.000000 , 0.707107 , 0.000000 , -0.707107 , -1.000000 , -0.707107 , -0.000000 , 0.707107 , 1.000000 , 0.707107 , 
0.000000 , -0.923880 , -0.707107 , 0.382683 , 1.000000 , 0.382683 , -0.707107 , -0.923880 , -0.000000 , 0.923880 , 0.707107 , -0.382683 , -1.000000 , -0.382683 , 0.707107 , 0.923880 , 
0.000000 , -1.000000 , -0.000000 , 1.000000 , 0.000000 , -1.000000 , -0.000000 , 1.000000 , 0.000000 , -1.000000 , -0.000000 , 1.000000 , 0.000000 , -1.000000 , -0.000000 , 1.000000 , 
0.000000 , -0.923880 , 0.707107 , 0.382683 , -1.000000 , 0.382683 , 0.707107 , -0.923880 , -0.000000 , 0.923880 , -0.707107 , -0.382683 , 1.000000 , -0.382683 , -0.707107 , 0.923880 , 
0.000000 , -0.707107 , 1.000000 , -0.707107 , -0.000000 , 0.707107 , -1.000000 , 0.707107 , 0.000000 , -0.707107 , 1.000000 , -0.707107 , -0.000000 , 0.707107 , -1.000000 , 0.707107 , 
0.000000 , -0.382683 , 0.707107 , -0.923880 , 1.000000 , -0.923880 , 0.707107 , -0.382683 , -0.000000 , 0.382683 , -0.707107 , 0.923880 , -1.000000 , 0.923880 , -0.707107 , 0.382683 , 
0.000000 , -0.000000 , 0.000000 , -0.000000 , 0.000000 , -0.000000 , 0.000000 , -0.000000 , 0.000000 , -0.000000 , 0.000000 , -0.000000 , 0.000000 , 0.000000 , 0.000000 , -0.000000 , 
0.000000 , 0.382683 , -0.707107 , 0.923880 , -1.000000 , 0.923880 , -0.707107 , 0.382683 , -0.000000 , -0.382683 , 0.707107 , -0.923880 , 1.000000 , -0.923880 , 0.707107 , -0.382683 , 
0.000000 , 0.707107 , -1.000000 , 0.707107 , -0.000000 , -0.707107 , 1.000000 , -0.707107 , 0.000000 , 0.707107 , -1.000000 , 0.707107 , -0.000000 , -0.707107 , 1.000000 , -0.707107 , 
0.000000 , 0.923880 , -0.707107 , -0.382683 , 1.000000 , -0.382683 , -0.707107 , 0.923880 , -0.000000 , -0.923880 , 0.707107 , 0.382683 , -1.000000 , 0.382683 , 0.707107 , -0.923880 , 
0.000000 , 1.000000 , -0.000000 , -1.000000 , 0.000000 , 1.000000 , -0.000000 , -1.000000 , 0.000000 , 1.000000 , -0.000000 , -1.000000 , 0.000000 , 1.000000 , 0.000000 , -1.000000 , 
0.000000 , 0.923880 , 0.707107 , -0.382683 , -1.000000 , -0.382683 , 0.707107 , 0.923880 , 0.000000 , -0.923880 , -0.707107 , 0.382683 , 1.000000 , 0.382683 , -0.707107 , -0.923880 , 
0.000000 , 0.707107 , 1.000000 , 0.707107 , -0.000000 , -0.707107 , -1.000000 , -0.707107 , 0.000000 , 0.707107 , 1.000000 , 0.707107 , 0.000000 , -0.707107 , -1.000000 , -0.707107 , 
0.000000 , 0.382683 , 0.707107 , 0.923880 , 1.000000 , 0.923880 , 0.707107 , 0.382683 , -0.000000 , -0.382683 , -0.707107 , -0.923880 , -1.000000 , -0.923880 , -0.707107 , -0.382683};