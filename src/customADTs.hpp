#include <iostream>
//#include <algorithm>

#define VECTOR_SIZE_BLOCK 20
template <typename Object>
class Vector
{
public:
    /*
    Constructor made explicit so that only correct syntax can be used to initialise the vector.
    */
    explicit Vector(int size = 0) : length{size}, cap{length + VECTOR_SIZE_BLOCK}
    {
        objects = new Object[cap];
        std::cout<<"Constructor called\n";
    }

    /* Destructor */
    ~Vector()
    {
        delete[] objects;
    }

    /* Copy Constructor */
    Vector(const Vector &vec): length{vec.length}, cap{vec.cap}, objects{nullptr}
    {
        objects = new Object[vec.cap];
        for (int i = 0; i < length; i++)
        {
            objects[i] = vec.objects[i];
        }
        std::cout<<"Copy Constructor called\n";
    }
    /* Copy Assignment operator */
    Vector & operator=(const Vector &vec)
    {
/*      This implementation works if move assignemnt  and move cinstructor are not defined

        length = vec.length;
        cap = vec.cap;
        delete [] objects;
        objects = new Object[vec.cap];
        for (int i = 0; i < length; i++)
        {
            objects[i] = vec.objects[i];
        }
        std::cout<<"Copy Assignment operator called\n";
  */

        /*This implementation relies on swap, which uses move constructor and move assignemnt operators. Hence these should be madatorily defined*/
        Vector tmp = vec;
        std::swap(*this, tmp);

       return *this;
    }
    /* Move Constructor */
    Vector(Vector &&vec): length{vec.length}, cap{vec.cap}, objects{vec.objects}
    {
        vec.cap = 0;
        vec.length = 0;
        vec.objects = nullptr;
        std::cout<<"Move constructor called\n";
    }

    /*Move assignment operator*/
    Vector & operator=(Vector &&vec)
    {
        std::swap(cap, vec.cap);
        std::swap(length, vec.length);
        std::swap(objects, vec.objects);
        std::cout<<"Move Assignment operator called\n";
        return *this;
    }
    /* method to get the size of vector */
    int size() const
    {
        return length;
    }
    /* Method to get the current capacity of the vector */
    int capacity() const
    {
        return cap;
    }

    const auto &getArr() const
    {
        return objects;
    }

private:
    int length;
    int cap;
    Object *objects;
};