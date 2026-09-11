# Đa nhiệm & Xử lý đồng thời (Concurrency & Synchronization)

Concurrency cho phép ứng dụng xử lý nhiều công việc cùng một lúc, nhưng đồng thời xuất hiện các bài toán phức tạp về tranh chấp tài nguyên.

---

## 1. Race Condition & Critical Section

**Critical Section**: Đoạn code truy cập vào tài nguyên dùng chung (Shared Resource: biến toàn cục, file, DB).

**Race Condition**: Xảy ra khi nhiều Thread cùng truy cập và thay đổi tài nguyên dùng chung đồng thời, làm cho kết quả cuối cùng phụ thuộc vào thứ tự thực thi ngẫu nhiên của các Thread.

### Ví dụ Race Condition:
```text
Thread A: Đọc Count = 10 ──> Tăng thành 11 ──> Ghi lại Count = 11
Thread B: Đọc Count = 10 ──> Tăng thành 11 ──> Ghi lại Count = 11
=> Kết quả đúng phải là 12, nhưng kết quả thực tế bị mất dữ liệu (Count = 11).
```

---

## 2. Các cơ chế đồng bộ (Synchronization Primitives)

Để đảm bảo tính Mutual Exclusion (Độc quyền truy cập) trong Critical Section, hệ điều hành có các cơ chế đồng bộ sau:

A. Mutex (Mutual Exclusion Lock): Hoạt động như một chiếc chìa khóa. Chỉ duy nhất 1 Thread nắm giữ Mutex mới được vào Critical Section. Các Thread khác phải chờ cho đến khi Mutex được Release.

B. Semaphore
- Là một biến đếm (Counter) dùng để giới hạn số lượng Thread truy cập vào tài nguyên cùng lúc.
- **Counting Semaphore**: Cho phép tối đa N Thread cùng truy cập (ví dụ: Database Connection Pool).
- **Binary Semaphore**: Đếm từ 0 đến 1 (tương tự Mutex nhưng không có khái niệm Ownership).

C. Spinlock
- Thread chờ sẽ liên tục vòng lặp kiểm tra Lock (Busy Waiting) thay vì rơi vào trạng thái Sleep/Blocked.
- Được sử dụng khi thời gian chờ cực ngắn để tránh chi phí Context Switch.

## 3. Deadlock

**Deadlock** là trạng thái mà hai hoặc nhiều tiến trình bị tắc nghẽn vĩnh viễn vì mỗi tiến trình đều chờ đợi tài nguyên mà tiến trình kia đang nắm giữ.

```text
[ Process A ] ──Holding──> [ Resource 1 ] <──Waiting─── [ Process B ]
     │                                                       │
     └─────Waiting──────> [ Resource 2 ] <──Holding──────────┘
```

Điều kiện để xảy ra Deadlock:

1. Mutual Exclusion: Tài nguyên không thể chia sẻ.
2. Hold and Wait: Tiến trình đang giữ tài nguyên và chờ cấp phát tài nguyên mới.
3. No Preemption: Không thể tranh đoạt tài nguyên khi tiến trình chưa tự giải phóng.
4. Circular Wait: Tồn tại chuỗi chờ vòng tròn giữa các tiến trình.

=> **Cách khắc phục thực tế**: Đảm bảo thứ tự khóa tài nguyên đồng nhất (Lock Ordering), thiết lập Lock Timeout, hoặc sử dụng cơ chế Lock-free data structures.
