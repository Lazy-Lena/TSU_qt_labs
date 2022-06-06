#include <QCoreApplication>
#include <exception>
#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class EStackEmpty
{
private:
    char* message;
public:
    EStackEmpty(const char* arg_message)
    {
        message = new char[strlen(arg_message)+1];
        strcpy(message,arg_message);
    }
    EStackEmpty(const EStackEmpty& arg)
    {
        message = new char[strlen(arg.message)+1];
        strcpy(message,arg.message);
    }
    ~EStackEmpty()
    {
        delete message;
    }
    const char* what() const { return message; }
};

template <typename T>
class Stack{
    private:
        T* data;
        int capacity;
        int length;
        int step;
        void expansion(){
            capacity += step;
            T* temp = new T[capacity];
            for(int i = 0;i < length;i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
        }
        void reduction(){
            capacity -= step;
            T* temp = new T[capacity];
            for(int i = 0;i < length;i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
        }
        void copy(const Stack& st){
            delete[] data;
            capacity = st.capacity;
            length = st.length;
            step = st.step;
            data = new T[capacity];
            for(int i = 0 ; i < length; i++){
                data[i] = st.data[i];
            }
        }
    public:
        Stack(){
            step = 10;
            length = 0;
            capacity = step;
            data = new T[capacity];
        }
        void push(const T p){
            length++;
            data[length - 1] = p;
            if(length == capacity){
                expansion();
            }
        }
        T pop(){
            if(length == 0){
                throw EStackEmpty("Stack in Empty");
            }
            T temp = data[length - 1];
            length--;
            if(length + step + 1 < capacity){
                reduction();
            }
            return temp;
        }
        ~Stack(){
            delete[] data;
        }
        Stack& operator=(const Stack& st){
            copy(st);
            return *this;
        }
        const int& getLength() const{ return length;}
        const int& getCapacity() const{ return capacity;}
};

class Person
{
private:
    string last_name;
    string first_name;
    string patronymic;
public:
    Person(){
        last_name = "";
        first_name = "";
        patronymic = "";
    }
    Person(const Person& p){
        last_name = p.last_name;
        first_name = p.first_name;
        patronymic = p.patronymic;
    }
    const string& getLastName() const { return last_name; }
    const string& getFirstName() const { return first_name; }
    const string& getPatronymic() const { return first_name; }
    void setLastName(const std::string& st){
        last_name = st;
    }
    void setFirstame(const std::string& st){
        first_name = st;
    }
    void setPatronymic(const std::string& st){
        patronymic = st;
    }
};


class PersonKeeper{
    private:
        static PersonKeeper *instance;
        PersonKeeper(){}
    public:
        static PersonKeeper* getInstance(){
            if(instance == nullptr){
                instance = new PersonKeeper();
            }
            return instance;
        }
        Stack<Person> readPersons(ifstream& stream){
            Stack<Person> stack;
            Person temp;
            std::ios_base::iostate s = stream.exceptions();
            stream.exceptions(std::ios_base::eofbit);
            while (true)
            {
                try{
                    string st;
                    stream >> st;
                    temp.setFirstame(st);
                    stream >> st;
                    temp.setLastName(st);
                    stream >> st;
                    temp.setPatronymic(st);
                    stack.push(temp);
                }
                catch(const std::ios_base::failure&) {
                    break;
                }
            }
            return stack;
        }
        void writePersons(ofstream& stream,const Stack<Person>& stack){
            Stack<Person>stack_temp;
            stack_temp = stack;
            Person temp;
            while(stack_temp.getLength() >0){
                temp = stack_temp.pop();
                stream << temp.getFirstName() << " " << temp.getLastName() << " " << temp.getPatronymic() << endl;
            }
        }
};

PersonKeeper* PersonKeeper::instance = nullptr;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ifstream ifile("text.txt");
    PersonKeeper* pK = PersonKeeper::getInstance();
    Stack<Person> persons;
    persons = pK->readPersons(ifile);
    ifile.close();
    ofstream ofile("new_text.txt");
    pK->writePersons(ofile,persons);
    ofile.close();

    return a.exec();
 }
