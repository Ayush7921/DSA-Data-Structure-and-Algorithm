class MyCircularQueue {
public:
    
    int capacity;
    int currsize;
    int f;
    int r;
    int *arr;
    MyCircularQueue(int k) {
        capacity=k;
        currsize=0;
        f= 0;
        r=-1;
        arr = new int[k];
    }
    
    bool enQueue(int value) {
        if(currsize==capacity){
            return false;
        }

        r= (r+1)%capacity;
        arr[r]=value;
        currsize++;
        return true;

        
    }
    
    bool deQueue() {

        if(currsize==0){
            return false;
        }
        
        f=(f+1)%capacity;
        currsize--;
        return true;
    }
    
    int Front() {
        if(currsize==0){ return -1;}
        return arr[f];
        
    }
    
    int Rear() {
        if(currsize==0){ return -1;}
        return arr[r];
        
    }
    
    bool isEmpty() {
        return currsize==0;
    }
    
    bool isFull() {
        return currsize==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */