#include <iostream>
#include <algorithm>

template <typename Object>
class Vector
{
public:
    static const int VECTOR_SIZE_BLOCK = 20;
    /*
    Constructor made explicit so that only correct syntax can be used to initialise the vector.
    */
    explicit Vector(int size = 0) : length{size}, cap{length + VECTOR_SIZE_BLOCK}
    {
        objects = new Object[cap];
        std::cout << "Constructor called\n";
    }

    /* Destructor */
    ~Vector()
    {
        delete[] objects;
    }

    /* Copy Constructor */
    Vector(const Vector &vec) : length{vec.length}, cap{vec.cap}, objects{nullptr}
    {
        objects = new Object[vec.cap];
        for (int i = 0; i < length; i++)
        {
            objects[i] = vec.objects[i];
        }
        std::cout << "Copy Constructor called\n";
    }
    /* Copy Assignment operator */
    Vector &operator=(const Vector &vec)
    {
        /*      This implementation works if move assignemnt  and move constructor are not defined

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

        /*This implementation relies on swap, which uses move constructor
        and move assignemnt operators. Hence these should be madatorily
        defined*/
        Vector tmp = vec;
        std::swap(*this, tmp);

        return *this;
    }
    /* Move Constructor */
    Vector(Vector &&vec) : length{vec.length}, cap{vec.cap}, objects{vec.objects}
    {
        vec.cap = 0;
        vec.length = 0;
        vec.objects = nullptr;
        std::cout << "Move constructor called\n";
    }

    /*Move assignment operator*/
    Vector &operator=(Vector &&vec)
    {
        std::swap(cap, vec.cap);
        std::swap(length, vec.length);
        std::swap(objects, vec.objects);
        std::cout << "Move Assignment operator called\n";
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

    /*Routine to get the internal array stored by the vector
    NOTE: The standard library implementations may not contain
    this function*/
    const auto &getArr() const
    {
        return objects;
    }

    /*Routine to resize the vector*/
    void resize(int newSize)
    {
        if (newSize > cap)
        {
            reserve(newSize * 2);
        }
        length = newSize;
    }

    /*Reserve new capacity for the vector
    NOTE: This is a costly operation, to optimise the
    cost, the new capacity is generally multiples of the
    previous size*/
    void reserve(int newCapacity)
    {
        Object *newVec = new Object[newCapacity];
        for (int i = 0; i < cap; i++)
        {
            newVec[i] = std::move(objects[i]);
        }
        std::swap(objects, newVec);
        cap = newCapacity;
        delete[] newVec;
    }
    
    /*Define [] operator for the vector class
    This non-const version is used when non const
    vesion is needed*/
    Object &operator[](int index)
    {
        return objects[index];
    }

    /*Define [] operator for the vector class
    This const version is used when const
    vesion is needed*/
    const Object &operator[](int index) const
    {
        return objects[index];
    }

    /*function to check whether the vector is empty*/
    bool isEmpty() const
    {
        return (size() == 0);
    }

    /*Push back implementation for lvalue input*/
    void push_back(const Object &element)
    {
        if (length == cap)
        {
            reserve(cap * 2 + 1);
        }
        objects[length++] = element;
    }

    /*Push back implementation for rvalue input*/
    void push_back(Object &&element)
    {
        if (length == cap)
        {
            reserve(cap * 2 + 1);
        }
        objects[length++] = std::move(element);
    }

    /*Remove the last element from the vector*/
    void pop_back()
    {
        if(length > 0)
            --length;
    }

    /*Return the value of the last element in the vector
    Use this function only when the size() > 0*/
    const Object &back() const
    {
        return objects[length - 1];
    }

    typedef Object *iterator;
    typedef const Object *const_iterator;

    /*Return iterator to the first element*/
    iterator begin()
    {
        return &objects[0];
    }

    /*Return constant iterator to the first element*/
    const_iterator begin() const
    {
        return &objects[0];
    }

    /*Return iterator to the last element*/
    iterator end()
    {
        return &objects[length];
    }

    /*Return const iterator to the last element*/
    const_iterator end() const
    {
        return &objects[length];
    }

private:
    /*Current length of the vector*/
    int length;
    /*Current capacity of the vector, 
    till which length can be increased*/
    int cap;
    /*Handle for storing the object, internal array, which this
    vector class manages*/
    Object *objects;
};