#include <stdio.h>
  

int search(int key, int frame_items[], int frame_occupied)
{
	int i;
    for ( i = 0; i < frame_occupied; i++)
        if (frame_items[i] == key)
            return 1;
    return 0;
}

void printOuterStructure(int f){
	int i;
    printf("stream ");
    
    for( i = 0; i < f; i++)
        printf("Frame%d ", i+1);
}
void printCurrFrames(int item, int frame_items[], int frame_occupied, int f){
	int i;
    
   
    printf("\n%d \t\t", item);
    
  
    for( i = 0; i < f; i++){
        if(i < frame_occupied)
            printf("%d \t\t", frame_items[i]);
        else
            printf("- \t\t");
    }
}

int predict(int rs[], int frame_items[], int n, int index, int frame_occupied)
{
  
    int result = -1, farthest = index,i;
    for ( i = 0; i < frame_occupied; i++) {
        int j;
        for (j = index; j < n; j++) 
        { 
            if (frame_items[i] == rs[j]) 
            { 
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
 
       
        if (j == n)
            return i;
    }
  

    return (result == -1) ? 0 : result;
}
  
void optimalPage(int rs[], int n, int frame_items[], int f)
{

    int frame_occupied = 0,i;
    printOuterStructure(f);
    
   
    int hits = 0;
    for ( i = 0; i <n; i++) {
  

        if (search(rs[i], frame_items, frame_occupied)) {
            hits++;
            printCurrFrames(rs[i], frame_items, frame_occupied, f);
            continue;
        }
  
        
        if (frame_occupied < f){
            frame_items[frame_occupied] = rs[i];
            frame_occupied++;
            printCurrFrames(rs[i], frame_items, frame_occupied, f);
        }
     
        else {
            int pos = predict(rs, frame_items, n, i + 1, frame_occupied);
            frame_items[pos] = rs[i];
            printCurrFrames(rs[i], frame_items, frame_occupied, f);
        }
        
    }
    printf("\n\nHits: %d\n", hits);
    printf("Misses: %d", n - hits);
}
  

int main()
{
  
    int n,rs[n],i,f ;
    printf("enter the no of pages:");
    scanf("%d",&n);
    printf("enter the pages:");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&rs[i]);
	}
	 printf("enter the no of frames:");
    scanf("%d",&f);
    
    int frame_items[f];
    
    optimalPage(rs, n, frame_items, f);
    return 0;
}
