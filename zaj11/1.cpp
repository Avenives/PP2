#include <iostream>
#include <array>
using namespace std;

class VectoredList
{
    public:
        VectoredList() :first(nullptr), last(nullptr), BucketCount(1)
        {
            first=new Bucket;
            last=first;
        }

        void push_back(string s)
        {
            if(last->CurrentSize<Bucket::N)
            {
                last->A[last->CurrentSize]=s;
                ++(last->CurrentSize);
            }
            else
            {
                add_Bucket();
                last->A[last->CurrentSize]=s;
                ++(last->CurrentSize);
            }
        }

        void pop_back()
        {
            if(last->CurrentSize>0) --(last->CurrentSize);
            else
            {
                last=last->Prev;
                last->Next=nullptr;

                --BucketCount;
            }
        }

        string& operator[](int index) const
        {
            Bucket *temp=first;
            int r=(index%Bucket::N);
            index-=r;
            index/=Bucket::N;
            while(index)
            {
                temp=temp->Next;
                --index;
            }
            return temp->A[r];
        }

        VectoredList& operator=(const VectoredList* original)
        {
            VectoredList new_VectoredList();

            for(int i=0;i<original->VectoredListSize();++i)
            {
                this->push_back(original->operator[](i));
            }
            return *this;
        }

        class VectoredListIterator
        {
            public:
                VectoredListIterator(const VectoredList& new_VL, int c=0): VL(new_VL), cursor(c) {}

                bool operator!=(VectoredListIterator &other) const
                {
                    if((other.VL == this->VL)&&(other.cursor == this->cursor)) return true;
                    else return false;
                }

                bool good() const
                {
                    if(cursor>=0&&cursor<=((Bucket::N)*(VL.BucketCount-1)+(VL.last->CurrentSize))) return true;
                    else return false;
                }

                VectoredListIterator& operator++()
                {
                    ++cursor;
                    return *this;
                }

                VectoredListIterator operator++(int)
                {
                    VectoredListIterator temp=*this;
                    ++*this;
                    return temp;
                }

                VectoredListIterator& operator--()
                {
                    --cursor;
                    return *this;
                }

                VectoredListIterator operator--(int)
                {
                    VectoredListIterator temp=*this;
                    --*this;
                    return temp;
                }

                string* operator*() const
                {
                    return &VL.operator[](cursor);
                }

                string get() const
                {
                    return VL.operator[](cursor);
                }

                int cursor;
            private:
                const VectoredList& VL;

        };

    public:
        class Bucket
        {
            public:
                Bucket() :Prev(nullptr), Next(nullptr), CurrentSize(0)
                {
                    for(int i=0;i<N;++i)
                        A[i]="";
                }

                static const int N=10;
                Bucket *Prev;
                Bucket *Next;
                array<string,N> A;
                int CurrentSize;
        };

        void add_Bucket()
        {
            Bucket *temp = new Bucket;
            last->Next=temp;
            temp->Prev=last;
            last=temp;
            ++BucketCount;
        }

        bool operator==(const VectoredList &other) const
        {
            if(this->first!=other.first||this->last!=other.last||this->BucketCount!=other.BucketCount) return false;
            for(int i=0;i<VectoredListSize();++i)
            {
                if(this->operator[](i)!=other.operator[](i)) return false;
            }
            return true;
        }

        int VectoredListSize() const
        {
            return ((Bucket::N)*(BucketCount-1)+(last->CurrentSize));
        }

        VectoredListIterator begin()
        {
            VectoredListIterator temp=VectoredListIterator(*this);
            return temp;
        }

        VectoredListIterator end()
        {
            VectoredListIterator temp=VectoredListIterator(*this,(Bucket::N)*(BucketCount-1)+(last->CurrentSize)+1);
            return temp;
        }

        VectoredListIterator erase(VectoredListIterator it)
        {
            int n=it.cursor;
            while(n+1<=VectoredListSize())
            {
                this->operator[](n)=this->operator[](n+1);
                ++n;
            }
            pop_back();

            VectoredListIterator temp=VectoredListIterator(*this,it.cursor+1);
            return temp;
        }

        VectoredListIterator erase(VectoredListIterator it1,VectoredListIterator it2)
        {
            int diff=it2.cursor-it1.cursor;
            int n=it1.cursor;
            while(n+diff<=VectoredListSize())
            {
                this->operator[](n)=this->operator[](n+diff);
                ++n;
            }
            while(diff--)
            pop_back();
            VectoredListIterator temp=VectoredListIterator(*this,it1.cursor+1);
            return temp;
        }

        Bucket *first;
        Bucket *last;
        int BucketCount;
};

int main()
{
        VectoredList A;
        for(int i=0;i<101;++i)
            A.push_back("s" + to_string(i));

        for(VectoredList::VectoredListIterator ita(A,101);ita.good();--ita)
        {
            cout << ita.get() << " ";
            if(ita.cursor%10==0) cout << endl;
        }

        cout << "----------" << endl;
        for (const auto& element : A)
           cout << element << "AAA" << endl;

        VectoredList::VectoredListIterator it3(A,3);
        VectoredList::VectoredListIterator it33(A,33);
        VectoredList::VectoredListIterator it45(A,45);

        A.erase(it3);
        A.pop_back();
        A.pop_back();
        A.erase(it33,it45);
        for(int i=0;i<A.VectoredListSize();++i)
        {
            cout << A[i] << " ";
            if(i%10==0) cout << endl;
        }

        cout << endl << "----------" << endl;
        VectoredList B=A;
        for(int i=0;i<B.VectoredListSize();++i)
        {
            cout << B[i] << " ";
            if(i%10==0) cout << endl;
        }
}
