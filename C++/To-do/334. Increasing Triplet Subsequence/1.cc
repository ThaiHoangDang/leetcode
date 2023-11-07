#include <vector>
using namespace std;

// arroach: Đọc câu hỏi này, điều đầu tiên tôi nghĩ đến là liệu có thể giải được trong O(n) time với O(1)
//      space, như vậy thì đây sẽ là array traversing, cùng với đó là sử dụng các constant variables
//      để keep track một cái gì đấy. Nhưng mà là keep track gì? Tôi nghĩ thử với case [2,1,5,0,4,6]
//      tôi có thể traverse từ đầu đến đoạn value [1, 5]. Giờ thì tôi chỉ cần một value > 5 nữa là được r.
//      Nhưng mà ngay sau đó lại là value 0.. Không thể cùng lúc keep track cả [1, 5] và 0. Nếu tôi keep
//      track [1, 5] thì hãy nghĩ đến case thay vì 0 kia thì là -100, sau đấy là -99, -98 ([2, 1, 5, -100, -99, -98]); 
//      vậy là ko được r. Còn nếu tôi keep track 0 và skip qua [1, 5], nhỡ đâu giá trị tiếp theo và cũng là giá 
//      trị cuối cùng lại là 6 ([2, 1, 5, 0, 6]), cx ko đc. Sau một hồi xem CSGO, tôi chợt nghĩ, tại sao 
//      phải chọn như vậy, mà trong khi ta có thể keep track giá trị min tốt nhất để true, như vậy nếu gặp 
//      bất cứ giá trị nào lớn hơn min đấy thì cx đều oke... 

// runtime: O(n)
// space: O(1)


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num = 0, min1 = nums[0], min2 = nums[0];
        bool track = true;

        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i] > min1) { num++; min1 = nums[i]; }
            else {
                if (track || (! track && nums[i] < min2)) {
                    min2 = nums[i];
                } else {
                    min1 = nums[i];
                }
                track = ! track;
            }

            if (num == 2) return true;

        }

        return false;
    }
};


// [2,1,5,0,4,6]
// [4,6,1,2,3]
// [1, 2, 1, 3]
// [1,2,1,3]
// [6,7,1,2]