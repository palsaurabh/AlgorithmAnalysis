#include <iostream>

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
    }

    /* Destructor */
    ~Vector()
    {
        delete[] objects;
    }

    /* Copy Constructor */
    Vector(Vector &vec): length{vec.length}, cap{vec.cap}, objects{nullptr}
    {
        objects = new Object[vec.cap];
        for (int i = 0; i < length; i++)
        {
            objects[i] = vec.objects[i];
        }
    }
    /* Copy Assignment constructor */
    /* Move Constructor */
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