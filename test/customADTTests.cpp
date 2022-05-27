#include <gtest/gtest.h>
#include "customADTs.hpp"

class complexType
{
public:
    complexType() : complexTypeMember{20}
    {
    }
    explicit complexType(int complexTypeInit) : complexTypeMember{complexTypeInit}
    {
    }

    int get() const
    {
        return complexTypeMember;
    }

private:
    int complexTypeMember;
};

TEST(customADTVector, vectorCreateTest)
{
    Vector<complexType> vec{3};
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec.capacity(), 3 + VECTOR_SIZE_BLOCK);
    const complexType *arr = vec.getArr();
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<<arr[i].get()<<' ';
    }
    std::cout<<'\n';

    Vector<complexType> vec1(200);
    EXPECT_EQ(vec1.size(), 200);
    EXPECT_EQ(vec1.capacity(), 200 + VECTOR_SIZE_BLOCK);
    const complexType *arr1 = vec1.getArr();
    for(int i = 0; i < vec1.size(); i++)
    {
        std::cout<<arr1[i].get()<<' ';
    }
    std::cout<<'\n';

    Vector<complexType> vec2(vec1);
    EXPECT_EQ(vec2.size(), vec1.size());

    EXPECT_EQ(vec2.capacity(), vec1.capacity());
    const complexType *arr2 = vec2.getArr();
    const complexType *arrin = vec1.getArr();
    for(int i = 0; i < vec2.size(); i++)
    {
        EXPECT_EQ(arr2[i].get(), arrin[i].get());
    }
    std::cout<<'\n';

    Vector<complexType> vec3 = vec1;
    EXPECT_EQ(vec3.size(), 200);
    EXPECT_EQ(vec3.capacity(), 200 + VECTOR_SIZE_BLOCK);
    const complexType *arr3 = vec3.getArr();
    for(int i = 0; i < vec3.size(); i++)
    {
        std::cout<<arr3[i].get()<<' ';
    }
    std::cout<<'\n';

    vec = vec3;
    EXPECT_EQ(vec.size(), 200);
    EXPECT_EQ(vec.capacity(), 200 + VECTOR_SIZE_BLOCK);
    const complexType *arr4 = vec.getArr();
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<<arr4[i].get()<<' ';
    }
    std::cout<<'\n'; 

    Vector<complexType> vec4 = std::move(vec3);
    EXPECT_EQ(vec4.size(), 200);
    EXPECT_EQ(vec4.capacity(), 200 + VECTOR_SIZE_BLOCK);
    const complexType *arr5 = vec4.getArr();
    for(int i = 0; i < vec4.size(); i++)
    {
        std::cout<<arr5[i].get()<<' ';
    }
    std::cout<<'\n'; 

    vec4 = std::move(vec);
    EXPECT_EQ(vec4.size(), 200);
    EXPECT_EQ(vec4.capacity(), 200 + VECTOR_SIZE_BLOCK);
    const complexType *arr6 = vec4.getArr();
    for(int i = 0; i < vec4.size(); i++)
    {
        std::cout<<arr6[i].get()<<' ';
    }
    std::cout<<'\n'; 

    vec4.resize(192);
    EXPECT_EQ(vec4.size(), 192);
    EXPECT_EQ(vec4.capacity(), 200 + VECTOR_SIZE_BLOCK);

    vec4.resize(700);
    EXPECT_EQ(vec4.size(), 700);
    EXPECT_EQ(vec4.capacity(), 700*2);
    const complexType *arr7 = vec4.getArr();
    for(int i = 0; i < vec4.size(); i++)
    {
        std::cout<<arr7[i].get()<<' ';
    }
    std::cout<<'\n'; 

    EXPECT_FALSE(vec4.isEmpty());
    vec[0] = complexType{3};
    complexType var = vec[0];
    EXPECT_EQ(var.get(), 3);
}

