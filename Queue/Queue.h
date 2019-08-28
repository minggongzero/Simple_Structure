#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class T>
class Queue{
private:
    int fron;
    int rear;
    int msize;
    T* qu;
public:
    Queue(int thesize){
        msize = thesize + 1;
        fron = rear = 0;
        qu = new T[msize];
    }

    ~Queue(){
        delete[] qu;
    }

    void myclear(){
        fron = rear;
    }

    bool enQueue(const T item){
        if((rear+1)%msize == fron){
            //std::cout << "溢出" << std::endl;
            return false;
        }
        qu[rear] = item;
        rear = (rear+1)%msize;
        return true;
    }

    bool deQueue(T& item){
        if(rear == fron){
            //std::cout << "空队列" << std::endl;
            return false;
        }
        item = qu[fron];
        fron = (fron+1)%msize;
        return true;
    }

    bool getFront(T& item){
        if(rear == fron){
            //std::cout << "空队列" << std::endl;
            return false;
        }
        item = qu[fron];
        return true;
    }

    int length(){
        if(fron > rear){
            return msize-(fron-rear);
        }
        return rear-fron;
    }
};


#endif // QUEUE_H_INCLUDED
