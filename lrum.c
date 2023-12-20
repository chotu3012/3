#include<stdio.h>
#include<limits.h>

int checkHit(int rs, int queue[], int occupied){
    int i;
    for( i = 0; i < occupied; i++){
        if(rs == queue[i])
            return 1;
    }
    
    return 0;
}

void printFrame(int queue[], int occupied)
{   int i;
    for(i = 0; i < occupied; i++)
        printf("%d\t\t",queue[i]);
}

int main()
{
     int n;
     printf("enter n values:");
     scanf("%d",&n);
    int frames;
    printf("enter number of frames:");
    scanf("%d",&frames);
    int rs[n];
    printf("enter ref values:");
    int i;
    for(i=0;i<n;i++)
    {
    	scanf("%d",&rs[i]);
	}
    int queue[n];
    int distance[n];
    int occupied = 0;
    int pagefault = 0;
    
    printf("Page\t Frame1 \t Frame2 \t Frame3\n");
    
    for(i = 0;i < n; i++)
    {
        printf("%d:  \t\t",rs[i]);
  
        
        if(checkHit(rs[i], queue, occupied)){
            printFrame(queue, occupied);
        }
        
          else if(occupied < frames){
            queue[occupied] = rs[i];
            pagefault++;
            occupied++;
            
            printFrame(queue, occupied);
        }
        else{
            
            int max = INT_MIN;
            int index,j;
          
            for ( j = 0; j < frames; j++)
            {
                distance[j] = 0;
              int k;
                for(k = i - 1; k >= 0; k--)
                {
                    ++distance[j];

                    if(queue[j] == rs[k])
                        break;
                }
                
               
                if(distance[j] > max){
                    max = distance[j];
                    index = j;
                }
            }
            queue[index] = rs[i];
            printFrame(queue, occupied);
            pagefault++;
        }
        
        printf("\n");
    }
    
    printf("Page Fault: %d",pagefault);
    
    return 0;
}
