
// CPP program to demonstrate multithreading
// using three different callables.
#include <iostream>
#include <thread>
using namespace std;

template<typename T>
void showMinMax() {
    cout << "min: " << numeric_limits<T>::min() << endl;
    cout << "max: " << numeric_limits<T>::max() << endl;
    cout << endl;
}

// A dummy function
void foo(int Z)
{
//    for (int i = 0; i < Z; i++) {
//        cout << "Thread using function"
//                " pointer as callable\n";
//    }
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "short:" << endl;
    showMinMax<short>();
    cout << "int:" << endl;
    showMinMax<int>();
    cout << "long:" << endl;
    showMinMax<long>();
    cout << "float:" << endl;
    showMinMax<float>();
    cout << "double:" << endl;
    showMinMax<double>();
    cout << "long double:" << endl;
    showMinMax<long double>();
    cout << "unsigned short:" << endl;
    showMinMax<unsigned short>();
    cout << "unsigned int:" << endl;
    showMinMax<unsigned int>();
    cout << "unsigned long:" << endl;
    showMinMax<unsigned long>();}

// A callable object
class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "Thread using function"
                    " object as  callable\n";
    }
};

int main()
{
    cout << "Threads 1 and 2 and 3 "
            "operating independently" << endl;

    // This thread is launched by using
    // function pointer as callable
    thread th1(foo, 3);

    // This thread is launched by using
    // function object as callable
    thread th2(thread_obj(), 3);

    // Define a Lambda Expression
    auto f_test = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "Thread using lambda"
                    " expression as callable\n";
    };

    cout << "Test start 5 times";
    f_test(5);
    // This thread is launched by using
    // lamda expression as callable
    thread th3(f_test, 3);

    // Wait for the threads to finish
    // Wait for thread t1 to finish
    th1.join();
    auto th1_id = th1.get_id();
    cout << "th1 ID = "<< th1_id;

    // Wait for thread t2 to finish
    th2.join();

    // Wait for thread t3 to finish
    th3.join();

    return 0;
}
