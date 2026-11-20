#include <iostream>
using namespace std;

float Divide(float a, float b)
{
    float res = 0;
    if (b==0)
    {
        //cout << "Can't divide by zero!" << endl;
        throw exception("Can't divide by zero!");
    }
    if (b == 1)
    {
        throw 404;
    }
    if (b == 2)
    {
        throw "Can't divide by zero!";
    }
    if (b == 3)
    {
        throw true;
    }
    else
    {
        res = a / b;
        cout << "Result: " << res << endl;
        return res;
    }
    
}

class PasswordInvalidException:public exception
{
public:
    PasswordInvalidException(const char* message):exception(message){}
   
};

class SmallClassException:public exception
{

    int lenght;
public:
    SmallClassException(const char* m, int l) :lenght(l), exception(m) {
    }
    void Message()
    {
        cout << what() << endl;
        cout << "Actual lenght: " << lenght << endl;
    }
};

void validateLogin(const char* login, const char* password)
{
    if (strlen(password) < 6)
        throw SmallClassException("To small password",strlen(password));
    if (islower(password[0]) || isalpha(password[0]))
        throw PasswordInvalidException("Password is invalid");
    if (!isupper(login[0]) || !isalpha(login[0]))
        throw exception("Incorrect login");

    cout << "Loading............." << endl;
}

class MyArray
{
    int* arr;
    int size;
public:
    MyArray(int size = 20):size(size)
    {
        arr = new int[size] {};
    }
    void print()const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int getElement(int index)
    {
        if (index >= 0 && index < size)
            return arr[index];
        else
            throw out_of_range("Index is less than 0 or more than size");
    }
    void CheckLength(int len)
    {
        if (len < 0)
        {
            throw length_error("Some length error");
        }
        cout << "Length invalid" << endl;
    }
    void SetSize(int newSize)
    {
        if (newSize < 0)
            throw invalid_argument("New size is less than 0");
        else
        {
            int* temp = new int[newSize];
            for (int i = 0; i < size && i < newSize; i++)
            {
                temp[i] = arr[i];
            }
            delete[]arr;
            arr = temp;
            size = newSize;
        }
    }
};

int main()
{
    MyArray arr(10);
    arr.print();

    try
    {
        arr.getElement(100);

    }
    catch (out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    catch (length_error ex)
    {
        cout << ex.what() << endl;
    }
    


    char login[100];
    char password[100];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter login: "; cin >> login;
        cout << "Enter password: "; cin >> password;
        try
        {
            validateLogin(login, password);
        }
        catch (PasswordInvalidException ex)
        {
            cout << "Invalid.....do something" << endl;
            cout << "First letter must be small.a-z, A-Z, 0-1" << endl;
            cout << ex.what() << endl;
        }
        catch (SmallClassException ex)
        {
            ex.Message();
            cout << "Password must have lenght more than 6 symbols" << endl;
        }
        catch (exception ex)
        {
            cout << "General error" << endl;
            cout << ex.what() << endl;
            cout << "First symbol - big letter" << endl;
        }
        catch (...)
        {
            cout << "Unknown exception" << endl;
        }
        
    }







    //float a, b;
    //cout << "Enter number: ";
    //cin >> a >> b;

    //try
    //{
    //    float res = Divide(a, b);
    //    cout << "Result in main: " << res << endl;
    //}
    //catch (exception ex)
    //{
    //    cout << ex.what() << endl;
    //}
    //catch (int ex)
    //{
    //    cout << ex << endl;
    //}
    //catch (const char* ex)
    //{
    //    cout << ex << endl;
    //}
    //catch (bool ex)
    //{
    //    cout<<"Bool exception" << endl;
    //    cout << ex << endl;
    //}
    //catch (...)
    //{
    //    cout << "Unknown exception" << endl;
    //}


    


}

