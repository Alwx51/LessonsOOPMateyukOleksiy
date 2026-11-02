#include <iostream>
using namespace std;

//struct Element
//{
//    char letter;
//    int priority;
//    void Print()
//    {
//        cout << letter << " : " << priority << endl;
//    }
//};
//
//class QueueWithProperty
//{
//    Element* elements;
//    int count;
//public:
//    QueueWithProperty():elements(nullptr),count(0){}
//    ~QueueWithProperty()
//    {
//        if (elements!=nullptr)
//        {
//            delete[]elements;
//        }
//    }
//    void Eniqueue(Element el)
//    {
//        int index = 0;
//        while (index< count && elements[index].priority < el.priority)index++;
//        Element* temp = new Element[count + 1];
//        for (int i = 0; i < count; i++)
//        {
//            temp[i] = elements[i];
//        }temp[index] = el;
//        for (int i = index; i < count; i++)
//        {
//            temp[i + 1] = elements[i];
//        }
//        if (elements!=nullptr)
//        {
//            delete[]elements;
//        }
//        elements = temp;
//        count++;
//    }
//    bool isEmpty()
//    {
//        return count == 0;
//    }
//    Element Dequeue()
//    {
//        if (!isEmpty())
//        {
//            Element first = elements[0];
//            for (int i = 0; i < count; i++)
//            {
//                elements[i] = elements[i + 1];
//            }
//            count--;
//            return first;
//        }
//    }
//    void Print()
//    {
//        cout << "------------------------ Queue ---------------------------" << endl;
//        for (int i = 0; i < count; i++)
//        {
//            cout << elements[i].letter << elements[i].priority<<endl;
//        }
//        cout << "------------------------ Queue ---------------------------" << endl;
//
//    }
//
//
//
//
//
//
//
//
//};

struct Document
{
    string document;
    int priority;
    void Print()
    {
        cout << document << " : " << priority << endl;
    }
};

class QueueWithProperty
{
    Document* documents;
    int count;
public:
    QueueWithProperty() :documents(nullptr), count(0) {}
    ~QueueWithProperty()
    {
        if (documents != nullptr)
        {
            delete[]documents;
        }
    }
    void Enqueue(Document el)
    {
        int index = 0;
        while (index < count && documents[index].priority < el.priority)index++;
        Document* temp = new Document[count + 1];
        for (int i = 0; i < count; i++)
        {
            temp[i] = documents[i];
        }temp[index] = el;
        for (int i = index; i < count; i++)
        {
            temp[i + 1] = documents[i];
        }
        if (documents != nullptr)
        {
            delete[]documents;
        }
        documents = temp;
        count++;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    Document Dequeue()
    {
        if (!isEmpty())
        {
            Document first = documents[0];
            for (int i = 0; i < count; i++)
            {
                documents[i] = documents[i + 1];
            }
            count--;
            return first;
        }
    }
    void Print()
    {
        cout << "------------------------ Queue ---------------------------" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << documents[i].document << documents[i].priority << endl;
        }
        cout << "------------------------ Queue ---------------------------" << endl;

    }
};
    int main()
    {
        //practice
        QueueWithProperty q;
        int key;
        string doc;
        int priority;
        cout << "----------------- MENU ---------------------" << endl;
        cout << "1-add doc to print" << endl;
        cout << "2-print all docs" << endl;
        cout << "3-exit: " << endl;
        cin >> key;
        while (key!=0)
        {
            switch (key)
            {
            case 1:
                cout << "Enter doc: "; cin >> doc;

                cout << "Enter priority(1-guess,2-administrator,3-manager,4-director): "; cin >> priority;
                q.Enqueue(Document{ doc,priority });
                break;
            case 2:
                while (!q.isEmpty())
                {
                    cout << "Delete element: ";
                    q.Dequeue().Print();
                    cout << endl;
                }
            case 3:
                cout << "exit" << endl;
                break;
            default:
                break;
            }
        }
            
        
        







        /*Element el = { 'A',1 };
        q.Eniqueue(el);
        q.Eniqueue(Element{'B',2});
        q.Eniqueue(Element{'C',2});
        q.Eniqueue(Element{'G',2});
        q.Eniqueue(Element{'K',2});
        q.Print();
        q.Eniqueue(Element{ 'D',5 });
        q.Print();
        q.Eniqueue(Element{ 'Q',3 });
        q.Print();*/

        while (!q.isEmpty())
        {
            cout << "Delete element: ";
            q.Dequeue().Print();
            cout << endl;
        }
    }
