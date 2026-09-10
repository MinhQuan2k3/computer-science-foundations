# Phase 2 — OOP Completion

## Checklist

- [x] Encapsulation
- [x] Inheritance
- [x] Polymorphism
- [x] Abstraction
- [x] Composition vs Inheritance
- [x] Mỗi chủ đề có một file Java độc lập
- [x] Mỗi file có `main()` để kiểm tra kết quả
- [x] Không dùng dependency bên ngoài
- [x] Không có warning trong quá trình biên dịch và chạy

## 4 thuộc tính của OOP

### 1. Encapsulation - Đóng gói

Đóng gói dữ liệu và kiểm soát cách dữ liệu được truy cập/thay đổi thông qua public API.

### 2. Inheritance - Kế thừa

Một class con kế thừa đặc điểm và hành vi của class cha. Chỉ nên dùng khi tồn tại quan hệ `is-a` hợp lý và việc thay thế subclass cho superclass có ý nghĩa.

### 3. Polymorphism - Đa hình

Một reference của kiểu chung có thể trỏ tới các object thuộc những kiểu cụ thể khác nhau; lời gọi method có thể thực hiện hành vi khác nhau tùy object thực tế.

### 4. Abstraction - Trừu tượng

Chỉ expose những gì client cần biết và che giấu chi tiết implementation không cần thiết.

### 5. Composition vs Inheritance

Composition phù hợp với quan hệ `has-a` hoặc `uses-a`. Nó thường linh hoạt hơn inheritance vì behavior có thể được thay thế mà không tạo ra hierarchy cứng.
