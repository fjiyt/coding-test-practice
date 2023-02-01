#include <iostream>
#define MAX_ELEMENT 100000

using namespace std;

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

//힙 생성
HeapType heap1;

//힙 삽입
void insert_max_heap(HeapType *h, element item)
{
    int size;
    size = ++(h->heap_size);

    while((size!=1) && (item.key > h->heap[size/2].key))
    {
        h->heap[size]=h->heap[size/2];
        size /= 2;
    }
    h->heap[size] = item;
}
//힙 삭제
element delete_max_heap(HeapType *h)
{
    element item, temp;

    item=h->heap[1];
    temp=h->heap[h->heap_size];
    h->heap_size--;

    int parent =1;
    int child=2;

    while(child <= h->heap_size)
    {
        if((child < h->heap_size) && (h->heap[child].key < h->heap[child+1].key))
        {
            child++;
        }

        if(temp.key >= h->heap[child].key){
            break;
        }

        h->heap[parent]=h->heap[child];
        parent = child;

        child *= 2;
    }

    h->heap[parent]= temp;

    return item;
}

int main(void)
{
    int num;
    cin>>num;

    element tmp[num];
    element max;
    int max_index; //최대값의 인덱스

    for(int i=0; i<num; i++)
    {
        cin >> tmp[i].key;
    }
    for(int i=0; i<num; i++)
    {
        if(tmp[i].key ==0)
        {
            if(heap1.heap_size ==0){
                cout<<"0"<<endl;
            }
            else{
                max = delete_max_heap(&heap1);
                cout<<max.key<<endl;
            }

        }
        else if(tmp[i].key > 0)
        {
            insert_max_heap(&heap1,tmp[i]);
        }
    }
}