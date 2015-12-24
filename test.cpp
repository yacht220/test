#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class B;

class A
{
  public:
  A();
  virtual ~A();
  //A(const A& a);
  A& operator=(const A& a);
  
  
  void set(int value);
  int get();
  void showMember(const A& a);
  void showAnotherMember(const B& b);
  
  protected:
  
  private:
  void declarationWithoutDefinition();
  
  int m_data;
};

class B
{
  public:
  friend class A;
  B();
  virtual ~B();
  
  private:
  int m_val;
};

A::A()
{
  m_data = 0;
}

/*A::A(const A& a)
{
  printf("copy constructor\n");
}*/


A& A::operator=(const A& a)
{
  printf("assignment operation\n");
  m_data = a.m_data;
  return *this;
}

A::~A()
{
}

void A::showMember(const A& a)
{
  printf("show member of a:A %d\n", a.m_data);
}

void A::showAnotherMember(const B& b)
{
  printf("show another member of b:B %d\n", b.m_val);
}

void A::set(int value)
{
  m_data = value;
}

int A::get()
{
  return m_data;
}

B::B()
{
  m_val = 10;
}

B::~B()
{
}

class Base
{
    public:
        Base()
        {
            doSth();
        }
        
        virtual ~Base()
        {
        }

        virtual void doSth()
        {
            printf("Base.\n");
        }

        void doOther(Base& obj)
        {
            obj.doSth();
        }
};

class Sub : public Base
{
    public:
        virtual void doSth()
        {
            printf("Sub.\n");
        }

        void doMyThing()
        {
            doOther(*this);
        }
};



int main(int argc, char **argv)
{
/*    char a = *argv[1];
    printf("%c\n", a);
    switch(a)
    {
        default:
        case '1':
            printf("1\n");
            break;
        case '2':
            printf("2\n");
            break;
        case '3':
            printf("3\n");
            break;
    }
*/

    /*static char *strings[] ={
          "this is string one",
          "this is string two",
          "this is string three",
         };
    const int string_no = ( sizeof(strings) ) / ( sizeof(strings[0]) ); // 姝ｇ‘锛宻tings鍦ㄧ紪璇戠殑鏃跺€欏凡缁忕‘瀹氱殑绫诲瀷鍜岄暱搴︿簡銆?
    printf("sizeof(srtings) = %d\n", sizeof(strings));
    printf("string_no = %d\n", string_no);
    
    static char var = string_no; 
    int len= sizeof(var);        // 閿欒锛宲鍦ㄧ紪璇戞椂鎬佹棤娉曠‘瀹氶暱搴﹀拰绫诲瀷
    printf("len = %d\n", len);*/
 
    /* new added */
    /*for(int i = 0; i<10; i++)
    {
        char arr[i];
        printf("size of arr[] = %d\n", sizeof(arr));
    }
 

    static char* another_string = new char[string_no];
    another_string = "stringssdfsdfsdsdfsdfsdfsdf";
    int another_string_size = sizeof(another_string);
    printf("another_string_size = %d\n", another_string_size);
    printf("strlen of another_string = %d\n", strlen(another_string));

    int* value = NULL;
    printf("size of \"value\" = %d\n", sizeof(value)); */
    
    /*int arr[10][10][10];
    int value = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                arr[i][j][k] = value;
                value++;
            }
        }
    }
 
    int *p = (int *)arr;
    printf("p = %d, arr = %d\n", p, arr);
    int incr = 2;
    printf("*(p+%d) = %d\n", incr, *(p+incr));
    printf("*(arr+%d) = %d\n", incr, *(arr+incr));
    printf("(arr+%d)[0][0][0] = %d\n", incr, (arr+incr)[0][0][0]); // arr + n will point to arr[n][0][0]
    printf("arr[%d][0][0] = %d\n", incr, arr[incr][0][0]);
    
    
    int arr1[6] = {0, 1, 2, 3, 4, 5};
    printf("arr1 = %p\n", arr1);
    printf("&arr1 = %p\n", &arr1);
    printf("arr1+1 = %p\n", arr1+1); // arr1+1 will point to arr1[1]
    printf("&arr1+1 = %p\n", &arr1+1); // &arr+1 will point to arr1[6]
    printf("arr1 = %d\n", *(arr1+1));*/




    A x;
    x.set(5);
    printf("value of x.m_data = %d\n", x.get());   
    
    A y(x);
    printf("value of y.m_data = %d\n", y.get()); 
    
    A z;
    B beta;
    z = x;
    printf("value of z.m_data = %d\n", z.get()); 
    z.showMember(x);
    z.showAnotherMember(beta);







    Sub b; // Base.
    Base& a = b; 
    a.doSth(); // Sub.
    b.doMyThing(); // Sub.
   






    char* string=(char*)malloc(2048);
    printf("%p\n", string);
    string = "hello";
    printf("%p\n", string);
    printf("%s\n", string);

    return 1;

}

