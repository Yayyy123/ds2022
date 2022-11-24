#include <vector>
#include <functional>
using namespace std;


template <typename Comparable>
void insertionSort( vector<Comparable> & a )
//对任意的子序列进行排列
{
    for( int p = 1; p < a.size( ); ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        //移项

        int j;
        for( j = p; j > 0 && tmp < a[ j - 1 ]; --j )
            a[ j ] = std::move( a[ j - 1 ] );
        a[ j ] = std::move( tmp );
    }
}



template <typename Comparable>
void heapsort( vector<Comparable> & a )
//利用堆这种数据结构所设计的一种排序算法
{
  for( int i = a.size( ) / 2 - 1; i >= 0; --i )
    percDown( a, i, a.size( ) );
    //利用percDown建立一个堆
    //在这里通过调换，让父亲的元素总是大于孩子的元素，以满足排序递增的需求
  for( int j = a.size( ) - 1; j > 0; --j )
    {
      std::swap( a[ 0 ], a[ j ] );
        // 将最大的元素和最小的元素进行调换，以做到 “删除”的目的，并且排序
      percDown( a, 0, j );
        //一直重复此动作，知道滤除最小数目位置。
    }
}


inline int leftChild( int i )
//左孩子的下标
{
  return 2 * i + 1;
}


template <typename Comparable>
void percDown( vector<Comparable> & a, int i, int n )
//heapsort的内部方法，用来deleteMax和buildHeap
{
  int child;
  Comparable tmp;


  for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
      //把筛选出来的东西，存放在tmp中
    {
      child = leftChild( i );
        
    
      if( child != n - 1 && a[ child ] < a[ child + 1 ] )
        ++child;
        //选取左孩子与tmp进行比较
        //
   
      if( tmp < a[ child ] )
        a[ i ] = std::move( a[ child ] );
        //如果tmp比较小的时候，我们则将空位往下移
    
      else
    break;
        //不然则tmp已经找到合适的位置，循环结束
    }

  a[ i ] = std::move( tmp );
}

template <typename Comparable>
void mergeSort( vector<Comparable> & a,
                vector<Comparable> & tmpArray, int left, int right )
{
    if( left < right )
    {
      int center = ( left + right ) / 2;
        //将一整个排序组分成两个大小相同的组
      mergeSort( a, tmpArray, left, center );
        //对左边的组用mergesort进行递归排列
      mergeSort( a, tmpArray, center + 1, right );
        //对右边的数组用mergesort进行递归排列
      merge( a, tmpArray, left, center + 1, right );
        //合并两个组，并将结果存放在tmpArray中
    }
}

template <typename Comparable>
void mergeSort( vector<Comparable> & a )
{
  vector<Comparable> tmpArray( a.size( ) );
    //用于存放最终排列合并后的结果

  mergeSort( a, tmpArray, 0, a.size( ) - 1 );
}

template <typename Comparable>
void merge( vector<Comparable> & a, vector<Comparable> & tmpArray,
            int leftPos, int rightPos, int rightEnd )
//用于合并排好的序列方法函数
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    //存放结果的位置与子数起点对应
    int numElements = rightEnd - leftPos + 1;

    ///
    while( leftPos <= leftEnd && rightPos <= rightEnd )
        //当两个组都没有读到最后
        if( a[ leftPos ] <= a[ rightPos ] )
        //选取两个比较后较小的元素存入tmpArray中，并准备读取下一个元素
      tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        //将存放和比较的位置后翼1位
        else
      tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    while( leftPos <= leftEnd )
        //复制左半部分剩下的东西
        tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );

    while( rightPos <= rightEnd )
        //复制右半部分剩下的东西
        tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    for( int i = 0; i < numElements; ++i, --rightEnd )
        //将排好序tmpArray复制回原序列
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
}



template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;

    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );
    
    //对left，right和center三值进行排序
    //通过swap选出他们的中间值
    //在此时此刻，最小值位于a[left]，最大值则在a[right]

    std::swap( a[ center ], a[ right - 1 ] );

    return a[ right - 1 ];
    //返回中间值
}


template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
    //快速排列
{
    if( left + 10 <= right )
        //对比较长的序列效果更好，让他们进行迭代直至大数组变为小数组
    {
        const Comparable & pivot = median3( a, left, right );
        //运用上面所示的median3
        
        int i = left, j = right - 1;
        for( ; ; )
            //对元素进行分割
        {
            while( a[ ++i ] < pivot ) { }
            //当i小于中间值，将i右移

            while( pivot < a[ --j ] ) { }
            //当j大于中间值，将j左移

            if( i < j )
                std::swap( a[ i ], a[ j ] );
            //当i，j停止且交错时，让他们彼此之间进行交换
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );

        quicksort( a, left, i - 1 );
        quicksort( a, i + 1, right );
        //对较小组和较大组进行排序
    }
    else
        insertionSort( a, left, right );
    //如果是小数组，使用插入排序会快过使用quicksort
}


