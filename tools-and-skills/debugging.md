# Debugging

Debugging là quá trình tìm ra nguyên nhân, xác định vị trí và sửa lỗi trong chương trình.

Mục tiêu không chỉ là "sửa cho chạy được", mà là **thu hẹp phạm vi lỗi một cách có hệ thống**.

---

## 1. Debugging Workflow

Một quy trình debugging cơ bản:

```text
Bug xảy ra
   ↓
Reproduce
   ↓
Đọc error / stack trace
   ↓
Xác định phạm vi lỗi
   ↓
Đặt breakpoint / kiểm tra biến
   ↓
Đưa ra hypothesis
   ↓
Kiểm tra hypothesis
   ↓
Sửa lỗi
   ↓
Test lại
```

**Nguyên tắc quan trọng**: Không đoán mò và sửa ngẫu nhiên. Hãy thu hẹp phạm vi lỗi từng bước.

---

## 2. Reproduce the Bug

Trước tiên cần tạo lại lỗi một cách ổn định.

Ví dụ:

```text
Input: 10
Expected: 5
Actual: 10
```

Nếu lỗi có thể reproduce, việc tìm nguyên nhân sẽ dễ hơn nhiều.

Cần xác định:

- Input nào gây lỗi?
- Lỗi xảy ra ở bước nào?
- Có phải lúc nào cũng xảy ra không?
- Có điều kiện đặc biệt nào không?

---

## 3. Read the Stack Trace

Stack trace cho biết lỗi xảy ra ở đâu và chương trình đã đi qua những hàm nào.

Ví dụ Java:

```text
Exception in thread "main" java.lang.ArithmeticException: / by zero
    at Calculator.divide(Calculator.java:10)
    at Main.main(Main.java:5)
```

Đọc từ phần trên xuống:

```text
ArithmeticException: / by zero
        ↓
Calculator.java:10
        ↓
Main.java:5
```

Thông tin quan trọng nhất:

- **Exception type**: loại lỗi
- **Error message**: mô tả lỗi
- **File**: file xảy ra lỗi
- **Line number**: dòng cần kiểm tra
- **Call stack**: chuỗi các hàm đã được gọi

### Ví dụ

Nếu stack trace chỉ tới:

```text
Calculator.java:10
```

hãy mở dòng 10 trước, thay vì đọc toàn bộ project.

---

## 4. Narrow Down the Problem

Khi chưa biết nguyên nhân, hãy chia nhỏ phạm vi tìm kiếm.

Ví dụ:

```text
Application
    ↓
Module
    ↓
Class
    ↓
Method
    ↓
Line
    ↓
Variable
```

Thay vì kiểm tra toàn bộ chương trình, hãy đặt câu hỏi:

```text
Dữ liệu đầu vào có đúng không?
        ↓
Method có được gọi không?
        ↓
Tham số truyền vào có đúng không?
        ↓
Logic bên trong có đúng không?
        ↓
Kết quả trung gian có đúng không?
```

Đây là một trong những kỹ năng quan trọng nhất khi debugging.

---

## 5. Use a Debugger

Debugger cho phép chạy chương trình từng bước và quan sát trạng thái bên trong chương trình.

Các tính năng cơ bản:

| Feature | Purpose |
|---|---|
| Breakpoint | Tạm dừng chương trình tại một dòng |
| Step Over | Chạy dòng hiện tại và sang dòng tiếp theo |
| Step Into | Đi vào bên trong method được gọi |
| Step Out | Thoát khỏi method hiện tại |
| Variables | Xem giá trị các biến |
| Call Stack | Xem chuỗi method đang được gọi |
| Watch | Theo dõi một biểu thức hoặc biến |

---

## 6. Breakpoint

Breakpoint dừng chương trình tại vị trí cần kiểm tra.

Ví dụ:

```java
int a = 10;
int b = 0;

int result = a / b;
```

Đặt breakpoint trước:

```java
int result = a / b;
```

Sau đó kiểm tra:

```text
a = 10
b = 0
```

Ta có thể xác định ngay nguyên nhân là `b = 0`.

---

## 7. Step Over / Step Into

Giả sử:

```java
int result = calculateTotal(price, quantity);
```

### Step Over

Chạy toàn bộ `calculateTotal()` và chuyển sang dòng tiếp theo.

Dùng khi không cần kiểm tra chi tiết method.

### Step Into

Đi vào bên trong:

```java
calculateTotal()
```

Dùng khi nghi ngờ lỗi nằm trong method đó.

### Step Out

Nếu đã đi vào một method nhưng nhận ra không cần kiểm tra tiếp, Step Out để quay lại method gọi nó.

---

## 8. Inspect Variables

Debugger cho phép kiểm tra giá trị biến tại từng thời điểm.

Ví dụ:

```java
int total = price * quantity;
```

Có thể kiểm tra:

```text
price    = 100
quantity = 0
total    = 0
```

Điều này giúp phát hiện lỗi dữ liệu mà không cần thêm hàng chục dòng `System.out.println()`.

---

## 9. Logging vs Debugger

Logging vẫn hữu ích, nhưng không nên dùng `console.log` / `System.out.println()` tràn lan.

### Logging

Phù hợp khi:

- Theo dõi behavior của application
- Ghi lại lỗi trên server
- Điều tra vấn đề xảy ra trong production
- Theo dõi các event quan trọng

### Debugger

Phù hợp khi:

- Đang phát triển
- Cần tìm chính xác dòng gây lỗi
- Cần xem giá trị biến
- Cần theo dõi flow của chương trình
- Cần kiểm tra từng bước thực thi

**Nguyên tắc**: Dùng debugger để điều tra flow và state; dùng logging để quan sát behavior của application.

---

## 10. Form a Hypothesis

Không nên thay đổi code một cách ngẫu nhiên.

Ví dụ:

```text
Bug: Tổng tiền = 0

Hypothesis:
quantity có thể đang bằng 0.

Kiểm tra:
quantity = 0

Kết luận:
Hypothesis đúng.
```

Sau đó mới sửa:

```java
int total = price * quantity;
```

và kiểm tra lại bằng test case phù hợp.

---

## 11. Minimal Reproduction

Nếu lỗi phức tạp, hãy tạo một ví dụ nhỏ nhất có thể tái hiện lỗi.

Thay vì:

```text
Large application
 ├── UI
 ├── Database
 ├── API
 ├── Authentication
 └── Business logic
```

hãy cố gắng thu hẹp thành:

```text
Input
 ↓
One method
 ↓
Bug
```

Điều này giúp loại bỏ những thành phần không liên quan và làm nguyên nhân lỗi rõ hơn.

---

## 12. Common Debugging Mistakes

### Sửa ngẫu nhiên

```text
Code lỗi
→ sửa một dòng
→ chạy lại
→ vẫn lỗi
→ sửa dòng khác
```

Không hiệu quả vì không xác định được nguyên nhân thực sự.

### Console log quá nhiều

```java
System.out.println(a);
System.out.println(b);
System.out.println(c);
System.out.println(d);
System.out.println(e);
```

Có thể tạo ra rất nhiều output nhưng vẫn không hiểu được flow của chương trình.

### Chỉ nhìn dòng lỗi

Dòng báo lỗi có thể là nơi lỗi **bộc lộ**, không nhất thiết là nơi lỗi **được tạo ra**.

Ví dụ:

```text
Method A
   ↓
Method B
   ↓
Method C
   ↓
Exception
```

Cần kiểm tra cả call stack và dữ liệu được truyền qua các method.

### Không reproduce lại sau khi sửa

Sau khi sửa lỗi cần kiểm tra:

```text
Original bug
     ↓
Fix
     ↓
Test original case
     ↓
Test related cases
```

Mục tiêu là đảm bảo lỗi đã được sửa mà không tạo ra regression.

---

## 13. Practical Debugging Checklist

Khi gặp bug, tạo checklist theo mẫu sau:

```text
[ ] 1. Reproduce the bug
[ ] 2. Read the error message
[ ] 3. Read the stack trace
[ ] 4. Find the relevant file and line
[ ] 5. Narrow down the scope
[ ] 6. Set a breakpoint
[ ] 7. Inspect variables
[ ] 8. Step through the code
[ ] 9. Form and test a hypothesis
[ ] 10. Fix the root cause
[ ] 11. Re-run the original case
[ ] 12. Test related cases
```

---

## 14. Key Takeaways

Debugging tốt cần:

- Biết đọc **error message và stack trace**
- Biết dùng **breakpoint và debugger**
- Biết **inspect variables và call stack**
- Biết **thu hẹp phạm vi lỗi**
- Biết đưa ra và kiểm chứng **hypothesis**
- Không sửa code một cách ngẫu nhiên
- Không phụ thuộc vào `console.log` / `System.out.println()` tràn lan
- Luôn kiểm tra lại sau khi sửa lỗi

**Debugging không phải là đoán xem lỗi nằm ở đâu. Đó là quá trình thu hẹp phạm vi một cách có hệ thống để xác định vị trí chính xác của lỗi.**
