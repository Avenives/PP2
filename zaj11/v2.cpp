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
            if(last->CurrentSize>1) --(last->CurrentSize);
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

            for(int i=0;i<original->size();++i)
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
                    if((other.VL == this->VL)&&(other.cursor == this->cursor)) return false;
                    else return true;
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

                string operator*() const
                {
                    return VL.operator[](cursor);
                }

                string get() const
                {
                    return VL.operator[](cursor);
                }

                operator string()
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
            for(int i=0;i<size();++i)
            {
                if(this->operator[](i)!=other.operator[](i)) return false;
            }
            return true;
        }

        int size() const
        {
            return ((Bucket::N)*(BucketCount-1)+(last->CurrentSize));
        }

        VectoredListIterator begin() const
        {
            VectoredListIterator temp=VectoredListIterator(*this);
            return temp;
        }

        VectoredListIterator end() const
        {
            VectoredListIterator temp=VectoredListIterator(*this,(Bucket::N)*(BucketCount-1)+(last->CurrentSize));
            return temp;
        }

        VectoredListIterator erase(VectoredListIterator it)
        {
            int n=it.cursor;
            while(n+1<size())
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
            while(n+diff<=size())
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
/*
        //opcjonalny test:
        VectoredList::VectoredListIterator it32(A,32);
        VectoredList::VectoredListIterator it55(A,55);
        A.erase(it32,it55);
*/
        for(VectoredList::VectoredListIterator ita(A,A.size()-1);ita.good();--ita)
        {
            cout << *ita << " ";
            if(ita.cursor%10==0) cout << endl;
        }
        cout << endl << "---" << endl;

        VectoredList V;
        V.push_back("foreach0");
        V.push_back("foreach1");
        V.push_back("foreach2");

        for (const auto& element : V)
        cout << element << endl;

        cout << "---" << endl;

        VectoredList B;
        for(int i=0;i<22;++i)
        B.push_back("b" + to_string(i));

        VectoredList::VectoredListIterator it2(B,2);
        B.erase(it2);

        for(VectoredList::VectoredListIterator itb(B,0);itb.good();++itb)
        {
            cout << *itb << " ";
            if(itb.cursor%10==0) cout << endl;
        }
        cout << endl << "---" << endl;

        VectoredList C;
        C=B;
        cout << "C=B:" << endl;
        for(VectoredList::VectoredListIterator it(C,0);it.good();++it)
        {
            cout << *it << " ";
            if(it.cursor%10==0) cout << endl;
        }
        cout << endl << "---" << endl;
}
