# Quản lý bộ nhớ (Memory Management)

Hệ điều hành quản lý bộ nhớ để đảm bảo tính an toàn, hiệu quả và cung cấp không gian bộ nhớ ảo cho các tiến trình.

---

## 1. Cấu trúc bộ nhớ của một Process (Memory Layout)

```text
+-----------------------+ High Address (0xFFFF...)
| Stack                 | (Chứa biến cục bộ, tham số hàm, return address - Phát triển xuống)
|   │                   |
|   ▼                   |
|                       |
|   ▲                   |
|   │                   |
| Heap                  | (Cấp phát động: malloc, new - Phát triển lên)
+-----------------------+
| Uninitialized Data    | (.bss)
+-----------------------+
| Initialized Data      | (.data - Biến toàn cục, biến static)
+-----------------------+
| Text / Code Segment   | (Mã máy thực thi - Read Only)
+-----------------------+ Low Address (0x0000...)
```

---

## 2. Stack vs Heap Memory

## 3. Bộ nhớ ảo (Virtual Memory) & Paging

**Virtual Memory** là kỹ thuật tạo ra một không gian địa chỉ bộ nhớ ảo liên tục cho mỗi Process, tách biệt hoàn toàn với RAM vật lý.

Cơ chế Paging (Phân trang):

1. Bộ nhớ ảo được chia thành các khối kích thước cố định gọi là Virtual Pages (thường là 4KB).
2. RAM vật lý được chia thành các Page Frames cùng kích thước.
3. MMU (Memory Management Unit) dùng bảng Page Table để dịch từ địa chỉ ảo (Virtual Address) sang địa chỉ vật lý (Physical Address).

```text
[ Process ] ──> Virtual Address ──> [ MMU / Page Table ] ──> Physical Address ──> [ Physical RAM ]
```

---

## 4. Các sự cố bộ nhớ thực tế

- **Page Fault**: Xảy ra khi CPU truy cập một Page chưa được load vào RAM (đang nằm ở Swap/Pagefile trên ổ đĩa). OS sẽ tạm dừng Process để đọc dữ liệu từ đĩa vào RAM.
- **Thrashing**: Xảy ra khi RAM bị thiếu trầm trọng, OS liên tục Swap Out/Swap In các Page giữa RAM và Ổ đĩa khiến toàn bộ hệ thống bị treo cứng (High I/O Wait).
- **Memory Leak**: Tiến trình xin cấp phát bộ nhớ trên Heap nhưng không giải phóng sau khi sử dụng xong (hoặc không được Garbage Collector thu hồi), khiến dung lượng RAM occupied tăng liên tục theo thời gian.
