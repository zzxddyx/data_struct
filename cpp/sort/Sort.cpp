#include "Sort.h"

/*
 * 1.比较相邻的元素,如果后一个元素比前一个元素大,则调换位置
 * 2.这样一遍下来,最后一个元素是最大的
 * 3.排除最后一个数,重复执行1.2
 *  时间复杂度为O(n2)
 */
void Sort::BubbleSort(int *arr, int length)
{
    for (int i = 1; i < length; ++i)
    {
        for (int j = 0; j < length - i; ++j)
        {
            if (arr[j+1] < arr[j])
            {
                this->Swap(arr[j], arr[j+1]);
            }
        }
    }
}

/*
 * 1. 从序列中挑出一个元素作为基准
 * 2. 排序数列,将小于基准的元素放在基准前面;将大于基准的元素放在基准的后面
 * 3. 递归的重复执行1.2步骤排序基准前后的序列
 *  时间复杂度为O(nlogn)
 */
void Sort::QuicklSort(int *arr, int left, int right)
{
    if (left >= right)
        return;

    int low = left;
    int high = right;
    int key = arr[low];

    while(low < high)
    {
        while(low < high && arr[high] >= key)
            --high;
        arr[low] = arr[high];

        while(low < high && arr[low] <= key)
            ++low;
        arr[high] = arr[low];
    }

    arr[low] = key;
    QuicklSort(arr, left, low-1);
    QuicklSort(arr, low+1, right);
}

/*
 * 1. 从位置1开始,比较该数与前面数的大小,如果小于前面的数则交换位置,直到不再小于为止
 * 2. 接着从2开始,直到不再小于为止
 *  时间复杂度为O(n2)
 */
void Sort::InsertSort(int *arr, int length)
{
    for(int i = 1; i < length; ++i)
    {
        int key = arr[i];
        int preIndex = i - 1;
        while (preIndex >= 0 && arr[preIndex] > key)
        {
            arr[preIndex+1] = arr[preIndex];
            preIndex--;
        }
        arr[preIndex+1] = key;
    }
}

/*
 * 1. 选择一个增量序列k1,k2...kt (ki > kt,t=1)
 * 2. 按增量序列个数k,对序列进行k趟排序
 * 3. 每趟排序根据对增量ti,将待排序列分割成若干长度为m的子序列,分别对子序列进行插入排序.当增量为1时,整个序列作为一个表来处理
 *  时间复杂度为O(n^(1.3—2))
 */
void Sort::ShellSort(int *arr, int length)
{
    int gap = length;
    while (gap > 1)
    {
        gap = gap/3+1;
        for (int i = gap; i < length; i+=gap)
        {
            int key = arr[i];
            int preIndex = i - gap;
            while(preIndex >= 0 && arr[preIndex] > key)
            {
                arr[preIndex+gap] = arr[preIndex];
                preIndex-=gap;
            }
            arr[preIndex+gap] = key;
        }
    }
}

/*
 * 1.在未排序的序列中找到最小值,存放到序列的开始位置
 * 2.在剩余未排序的序列中继续寻找最小值,然后放到已排序的尾部,直到所有元素被排序完为止
 *  时间复杂度为O(n2)
 */
void Sort::SelectSort(int *arr, int length)
{
    for (int i = 0; i < length-1; ++i)
    {
        int min = i;
        for (int j = i+1; j < length; ++j)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        this->Swap(arr[i], arr[min]);
    }
}

/*
 * 堆:每个结点的值都大于或等于其左右孩子结点的值,称为大顶堆;或者每个结点的值都小于或等于其左右孩子结点的值,称为小顶堆
 * 将待排序序列构造成一个大顶堆,此时,整个序列的最大值就是堆顶的根节点.
 * 将其与末尾元素进行交换,此时末尾就为最大值.
 * 然后将剩余n-1个元素重新构造成一个堆,这样会得到n个元素的次小值.
 * 如此反复执行,便能得到一个有序序列了
 */
void Sort::HeapSort(int *arr, int length)
{
    for(int i = length/2 - 1; i >= 0; --i)
    {
        this->BigHeadAdjust(arr, i, length);
    }

    for (int i = length - 1; i >= 0; --i)
    {
        this->Swap(arr[0], arr[i]);
        this->BigHeadAdjust(arr, 0, i);
    }
}

//堆调整 大堆顶,将最大值放在根结点
void Sort::BigHeadAdjust(int *arr, int index, int length)
{
    int lChild = index * 2 + 1;
    int rChild = index * 2 + 2;
    int max = index;

    if (lChild < length && arr[lChild] > arr[max])
        max = lChild;

    if (rChild < length && arr[rChild] > arr[max])
        max = rChild;

    if (max != index)
    {
        this->Swap(arr[max], arr[index]);
        this->BigHeadAdjust(arr, max, length);
    }
}

/*
 * 采用分治法的思想,将已有的子序列合并,得到完全有序的序列;即先使每个子序列有序,再使子序列段有序
 * 实现逻辑:
 * 1. 将长度为n的序列分成两个长度为n的子序列;
 * 2. 对每个子序列采用归并排序
 * 3. 对排序好的两个子序列进行合并
 */
void Sort::MergeSort(int *arr, int length)
{
    if (arr == NULL || length < 2)
        return;

    this->Spera(arr, 0, length-1);
}

void Sort::Spera(int *arr, int left, int right)
{
    if (left == right)
        return;

    int mid = (left+right)/2;
    this->Spera(arr, left, mid);
    this->Spera(arr, mid+1, right);
    this->Merge(arr, left, mid, right);
}

void Sort::Merge(int *arr, int left, int mid, int right)
{
    int *new_arr = new int[right-left+1];
    int i = 0;
    int pleft = left;
    int pRight = mid + 1;

    while(pleft <= mid && pRight <= right)
        new_arr[i++] = arr[pleft] < arr[pRight] ? arr[pleft++] : arr[pRight++];

    while(pleft <= mid)
        new_arr[i++] = arr[pleft++];

    while(pRight <= right)
        new_arr[i++] = arr[pRight++];

    for(int j = 0; j < (right-left+1); ++j)
    {
        arr[left+j] = new_arr[j];
    }
}

/*
 * 作为一种线性时间复杂度的排序,计数排序要求输入的数据必须是有确定范围的整数.
 * 实现逻辑:
 *  1.找出待排序数组中最大和最小值元素
 *  2.统计数组中每个值为i的元素出现的次数,存入数组i的第i项中
 *  3.对所有的计数累加(从桶中第0个元素开始,每一项和前一项想加)
 *  4.反向填充目标数组,将每个元素i放在目标数组的第i项
 *  5.每放一个元素都将目标数组个数减1
 *      时间复杂度O(n)
 */
void Sort::CountSort(int *arr, int length)
{
    if (arr == NULL || length < 2)
        return;

    int max = arr[0];
    int lastIndex = 0;

    for (int i = 1; i < length; ++i)
        max = arr[i] > max ? arr[i] : max;

    int *new_arr = new int[max+1]();
    for(int j = 0; j < length; ++j)
        new_arr[arr[j]]++;

    for(int k = 0; k < max+1; k++)
    {
        while(new_arr[k] > 0)
        {
            arr[lastIndex++] = k;
            new_arr[k]--;
        }
    }

    delete []new_arr;
}

/*
 * 假设输入数据服从均匀分布,将数据分到有限数量的桶里,每个桶再分别排序(有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排)
 * 实现逻辑:
 * 1.设置一个定量的数组作为桶
 * 2.遍历数组,将数据一个个的放进桶中
 * 3.对每个不是空的桶进行排序
 * 4.然后再从不是空的桶里将数据拼接起来
 */
void Sort::BucketSort(int *arr, int length, int size)
{
    if (arr == NULL || length < 2)
        return;

    int min = arr[0];
    int max = arr[0];
    int len = length;

    for (int i = 1; i < len; ++i)
    {
        min = arr[i] < min ? arr[i] : min;
        max = arr[i] > max ? arr[i] : max;
    }

    if (max == min)
        return;

    int bucketCount = static_cast<int>(ceil((max-min)/size)+1);
    cout << "bucketCount num : " << bucketCount << endl;
    vector<vector<int> > bucket(bucketCount);
    cout << "vector size : " << bucket.size() << endl;

    // 把数据放进桶中
    int pos = 0;
    for(int i = 0; i < len; ++i)
    {
        pos = this->GetGroupCount(arr[i], bucketCount, min, max);//均匀分布下
        cout << "pos " << pos << endl;
        bucket[pos].push_back(arr[i]);
    }

    //对桶中元素排序
    for (int i = 0; i < bucketCount; ++i)
    {
        for (int j = 1; j < bucket[i].size(); ++j)
        {
            if (bucket[i][j] < bucket[i][j-1])
                this->Swap(bucket[i][j], bucket[i][j-1]);
        }

        cout << "cout bucket info : " << endl;
        for (int j = 0; i < bucket[i].size(); ++j)
            cout << bucket[i][j] << " ";
        cout << endl;
    }

    int index = 0;
    for (int i = 0; i < bucketCount; ++i)
    {
        for(int j = 0; i < bucket[i].size(); ++j)
        {
            arr[index++] = bucket[i][j];
        }
    }
}

int Sort::GetGroupCount(int value, int size, int min, int max)
{
    return static_cast<int>((size*(value-min)) / (max-min));
}

/*
 * 基数排序是按照低位先排序,然后收集;再按照高位排序,然后再收集;依次类推,直到最高位
 * 实现逻辑:
 * 1.找到数组中最大的数,并取得位数
 * 2.arr为原始数组,从最低位开始取每个位组成radix数组
 * 3.对radix进行计数排序(利用计数排序适用于小范围数的特点)
 */
void Sort::RadixSort(int *arr, int length)
{
    if (arr == NULL || length < 2)
        return;

    int len = length;

    int max = arr[0];
    for(int i = 0; i < len; ++i)
        max = max > arr[i] ? max : arr[i];

    int radixCount = this->GetRadixCount(max);
    int tenRadixCount = GetTenRadixCount(radixCount);

    int (*bucket)[10] = new int[10][10];
    int *num = new int[10]();
    int multiplier = 1;

    while(multiplier < tenRadixCount)
    {
        for(int i = 0; i < len; ++i)
        {
            int curCount = arr[i]/multiplier%10;
            int k = num[curCount];
            bucket[curCount][k] = arr[i];
            num[curCount]++;
        }

        int index = 0;
        for(int j = 0; j < 10; ++j)
        {
            if(num[j] != 0)
            {
                for(int k = 0; k < num[j]; ++k)
                {
                    arr[index++] = bucket[j][k];
                }
            }
            num[j] = 0;
        }
        multiplier *= 10;
    }
}

int Sort::GetRadixCount(int value)
{
    int count = 1;
    while(value / 10 > 0)
        count += 1;

    return count;
}

int Sort::GetTenRadixCount(int value)
{
    int tenRadix = 1;
    while(value > 0)
    {
        tenRadix *= 10;
        value--;
    }
    return tenRadix;
}
