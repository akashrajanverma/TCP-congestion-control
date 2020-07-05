#include<bits/stdc++.h>
using namespace std;

template <typename T, int MaxLen, typename Container=std::deque<T>>
class FixedQueue : public std::queue<T, Container> {
public:
    void push(const T& value) {
        if (this->size() == MaxLen) {
           this->c.pop_front();
        }
        std::queue<T, Container>::push(value);
    }
    
    void popf()
    {
          this->c.pop_front();
    }
    
};

int pos=0;

int main()
{
     int a[]={1,2,3,4,5,6,7,8,9,0,9,8,7,6,5,4,3,2,3,45,6,5,67,8,4,2,45,7,9,7,5,4,2,2,3,4,6,86,3,5,4,2,2,6,77,5,3,7,5,2,4,6,89,5,2,5,7,8,4,69};
     FixedQueue<int,5>fq;
     FixedQueue<int,20>afq;
     cout<<"\nEnter your choice"<<endl;
     cout<<"\n1 . without auxiliary queue\n2 . with auxiliary queue"<<endl;
     
     int ch;
     cin>>ch;
     int size=3;
     switch(ch)
     {
          case 1:
               
               while(1)
               {
                    
                    try
                    {
                    
                         if(size>5)
                              throw 1;
                         for(int i=pos;i<size+pos;i++)
                         {
                              fq.push(a[i]);   
                         }
                         cout<<"\nProcessing......................"<<endl;
                         
                         while(fq.size())
                         {
                              int k = fq.front();
                              cout<<k<<" ";
                              fq.pop();
                         }
                         cout<<endl;
                         cout<<"Successfully packet send"<<endl;
                         cout<<endl;
                         pos+=size;

                    }
                    catch(int j)
                    {
                         cout<<"\nQueue limit full"<<endl;
                         return 1;
                    }
                    
                    size++;
               }
               break;
               
          case 2:
            
               size=3;
               while(pos<60)
               {
                    cout<<"Processing................"<<endl;
                    //int i=pos;
                    if(size<5)
                    {
                         for(int j=pos;j<size+pos;j++){
                              fq.push(a[j]);
                              cout<<a[j]<<" ";
                              fq.pop();
                         }
                         
                         cout<<"\nPackets successfully send."<<endl;
                    }
                    else
                    {
                          int j;
                          for(j=pos;j<5+pos;j++){
                              fq.push(a[j]);
                              cout<<a[j]<<" ";
                              fq.pop();
                         }
                         cout<<"\n Queue completed full. Packets dropped to the auxiliary queue."<<endl;
                         cout<<"Packets processed after the packets in main queue gets processed."<<endl;
                         for(;j<size+pos;j++)
                         {
                              afq.push(a[j]);
                              cout<<a[j]<<" ";
                              fq.pop();
                         }
                         
                    }
                    pos+=size;
                    size++;
               }
               break;
               
     }
     
     
}
