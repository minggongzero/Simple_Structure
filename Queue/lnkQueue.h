#ifndef LNKQUEUE_H_INCLUDED
#define LNKQUEUE_H_INCLUDED

template <class T>
class lnkQueue{
private:
    int mysize;
    Link<T>* fron;
    Link<T>* rear;
public:
    lnkQueue(){
        mysize = 0;
        fron = rear = 0;
    }

    ~lnkQueue(){
        myclear();
    }

    void myclear(){
        while(fron != 0){
            rear = fron;
            fron = fron->next;
            delete rear;
        }
        rear = 0;
        mysize = 0;
    }

    bool enQueue(const T item){
        if(rear == 0){
            fron = rear = new Link<T>(item, 0);
        }
        else{
            rear->next = new Link<T>(item, 0);
            rear = rear->next;
        }
        mysize++;
        return true;
    }

    bool deQueue(T& item){
        Link<T>* tmp;
        if(mysize == 0){
            return false;
        }
        &item = fron->data;
        tmp = fron;
        fron = fron->next;
        delete tmp;
        if(fron == 0){
            rear = 0;
        }
        mysize--;
        return true;
    }

    bool getFron(T& item){
        if(mysize == 0){
            return false;
        }
        item = fron->data;
        return true;
    }
};

#endif // LNKQUEUE_H_INCLUDED
