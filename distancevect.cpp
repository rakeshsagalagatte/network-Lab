#include<bits/stdc++.h>

using namespace std;
class Grid{

   public :
     int *weight;
     //char *nextHop;
     char *destination;
     Grid(){}

     Grid(int hops, int from){

        //this->nextHop = new char[hops];
        this->destination = new char[hops];
        this->weight = new int[hops];
        memset(this->weight, INT_MAX , hops);
        iota(this->destination, this->destination + hops , 97 );
        //memset(this->nextHop, '_' , hops);
        this->weight[from] = 0;
     }

     void print_nw(int n, int g){
        cout << " Destination and weight of router " << (char) (97+g) << endl;
        for(int i=0; i< n;i++){
             cout << this->destination[i] << " " << this->weight[i] << " " << endl;
        }
     }

};

Grid * creating_network(int hops, int n_w){
     Grid *grid = new Grid[hops];
     for(int i=0 ; i < hops ;i++){
        grid[i] = Grid(hops,i);
     }
     for(int i = 0 ;i < n_w ; i++){
        char from,to;
        int w;
        cout << "Enter the from hop , destination hop and weight : ";
         cin >> from >> to >> w;
         (grid+(from-97))->weight[to-97] = w;
         (grid+(to-97))->weight[from-97] = w;
     }
     return grid;
}
 
void distance_vector(Grid *grid, int n){
  
      for(int i=0;i < n;i++){
         for(int j=0 ; j < n ;j++){
            if(i==j) 
               continue;
            for(int k=0;k < n ; k++){
               if(k==i || k==j) 
                  continue;
               (grid+i)->weight[j] = min( (grid+i)->weight[j] , (grid+i)->weight[k] + (grid+k)->weight[j]);
               (grid+j)->weight[i] = (grid+i)->weight[j];
               
            }
            
         }
      }
}

void print_grid(Grid *grid, int n){
   for(int i=0;i<n;i++){
      (grid+i)->print_nw(n,i);
   }
}
int main(){

   int hops,n_w;
   cout << "Enter the number of hopes and connection between the hopes : ";
   cin >> hops >> n_w;
   Grid *grid = creating_network(hops,n_w);
   distance_vector(grid,hops);
   print_grid(grid,hops);
   for(int i=0; i<hops;i++ ){
      delete [] (grid + i)->destination;
      //delete [] (grid + i)->nextHop;
      delete [] (grid + i)->weight;
   }
   delete [] grid;
   return 0;
}