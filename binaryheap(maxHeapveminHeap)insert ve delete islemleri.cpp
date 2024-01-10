#include<stdio.h>
#include<stdlib.h>

void insertToMaxHeap(int *array, int x, int index){
	if(index==SIZE){
		printf("heap dolu");
	}
	else{
		array[index]=x;
		while(index!=1 && array[index/2]<array[index]){
			swap(&array[index/2],array[index]);
			index/=2;
		}
	}
}
void insertToMinHeap(int *array,int x,int index){
	if(index==SIZE){
		printf("heap dolu"); 
	}
	else{
		array[index]=x;
		while(index!=1 && array[index/2]> array[index]){
			swap(&array[index/2],array[index]);
			index/=2;
		}
	}
}
int deleteMaxHeap(int *array,int index){
	int max, int i=1;
	if(index==1){
		printf("heap bos..");	
		return 0;			
	}
	else{
		max=array[i];
		array[i]=array[index-1]; //son eleman basa atandi
		array[index-1]=0; 		 //son eleman silindi
		while(array[i]<array[2*i] || array[i]<array[(2*i)+1]){
			if(array[2*i]>array[(2*i)+1]){ //sol cocuk buyukse
				swap(array[2*i],array[i]);
				i=2*i;
			}
			else{ 	//sag cocuk büyükse
				swap(array[(2*i)+1],array[i]);
				i=(2*i)+1;
			}
		}
		return max;
	}
}
int deleteMinHeap(int *array, int index){
	int min, int i=1;
	if(index==1){
		printf("heap bos...");
		return 0;
	}
	else{
		min=array[i];
		array[i]=array[index-1];   //son eleman basa atandi
		array[index-1]=0;    	   //son eleman silindi
		while(array[i]>array[2*i] || array[i]>array[(2*i)+1]){
			if(array[2*i]>array[(2*i)+1]){
				swap(array[2*i],array[i]);
				i=2*i;
			}
			else{
				swap(array[(2*i)+1],array[i]);
				i=(2*i)+1;
			}
		}
		return min;
	}
}

void main(){
	
	return 0;
}
