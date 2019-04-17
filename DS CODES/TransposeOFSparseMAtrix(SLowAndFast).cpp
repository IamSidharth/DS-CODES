#include<iostream>
using namespace std;

class Sparse{
public:
    int row;
    int column;
    int value;

    void disp(Sparse s1);
    };

    void Sparse::disp(Sparse s1)
    {
        cout<<s1.row<<s1.column<<s1.value<<endl;
    }

    int main()
    {

        Sparse s1[10];
        cout<<"ENter m,n: ";
        int m,n;

        cin>>m>>n;
        int a[m][n];
        int t=1;
        cout<<"Enter elements: ";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]!=0)
                {
                    s1[t].row=i;
                    s1[t].column=j;
                    s1[t].value=a[i][j];
                    t++;
                }
            }
        }

        s1[0].row=m;
        s1[0].column=n;
        s1[0].value=t-1;

        for(int i=0;i<t;i++)
        {
            s1[0].disp(s1[i]);
        }

     Sparse s3[10],s4[10];
     int q=1;
/*     // slow transpose order value*clumn;
     for(int i=0;i<s1[0].column;i++)
     {
         for(int p=1;p<=s1[0].value;p++)
         {
             if(s1[p].column==i)
             {
                 s3[q].row=s1[p].column;
                 s3[q].column=s1[p].row;
                 s3[q].value=s1[p].value;
                 q++;

             }
         }
     }
     s3[0].column=s1[0].row;
      s3[0].row=s1[0].column;
       s3[0].value=s1[0].value;

       for(int i=0;i<=s3[0].value;i++)
        s3[0].disp(s3[i]);

*/

     //fast transpose  oder value+column;
     int count[10]={0},pos[10]={0},j,v;
    for(int i=1;i<=s1[0].value;i++)
    {
        j=s1[i].column;
       ++count[j];
    }
    pos[0]=1;
    for(int i=1;i<s1[0].column;i++)
    {
        pos[i]=pos[i-1]+count[i-1];
    }
    for(int i=1;i<=s1[0].value;i++)
    {
        v=pos[s1[i].column]++;
        s4[v].row=s1[i].column;
        s4[v].column=s1[i].row;
        s4[v].value=s1[i].value;

    }
    s4[0].column=s1[0].row;
      s4[0].row=s1[0].column;
       s4[0].value=s1[0].value;

        for(int i=0;i<=s4[0].value;i++)
        s4[0].disp(s4[i]);


    }
