# Tiến trình & Luồng (Process vs Thread)

Hiểu rõ sự khác biệt giữa Process và Thread giúp tối ưu hóa việc sử dụng tài nguyên CPU và bộ nhớ trong ứng dụng.

---

## 1. Định nghĩa & Bảng so sánh

* **Process (Tiến trình):** Là một chương trình đang được thực thi, sở hữu một không gian địa chỉ bộ nhớ (Address Space) độc lập do OS cấp phát.
* **Thread (Luồng):** Là đơn vị thực thi nhỏ nhất bên trong một Process. Các Thread trong cùng một Process chia sẻ chung không gian bộ nhớ.

| Tiêu chí | Process (Tiến trình) | Thread (Luồng) |
| :--- | :--- | :--- |
| **Không gian bộ nhớ** | Độc lập, cô lập hoàn toàn | Chia sẻ chung (Heap, Code, Data) |
| **Chi phí tạo/hủy** | Nặng (Heavyweight), tốn tài nguyên | Nhẹ (Lightweight), khởi tạo nhanh |
| **Context Switch** | Chậm (Phải đổi Page Table, Flush TLB) | Nhanh (Chỉ lưu trạng thái Registers & Stack) |
| **An toàn (Safety)** | Cao (Một Process sập không làm sập Process khác) | Thấp (Một Thread crash/lỗi bộ nhớ có thể làm sập toàn bộ Process) |
| **Giao tiếp (IPC)** | Phức tạp (Dùng IPC: Sockets, Shared Memory, Pipes) | Đơn giản (Truy cập trực tiếp biến toàn cục/Heap) |

---

## 2. Tiến trình chuyển trạng thái (Process State Lifecycle)

```text
[ New ] ──(Admitted)──> [ Ready ] <──(Scheduler Dispatch)──> [ Running ] ──(Exit)──> [ Terminated ]
                           ▲                                      │
                           └──────────── (Interrupt) ─────────────┤
                                                                  │
                                                      (I/O or Event Wait)
                                                                  │
                                                                  ▼
                                                             [ Waiting ]
                                                          (or Blocked)
                                                                  │
                                                          (I/O Event Complete)
                                                                  │
                                                                  └───> Go to [ Ready ]
```

---

## 3. Chuyển đổi ngữ cảnh (Context Switch)

**Context Switching** là quá trình OS lưu lại trạng thái của Process/Thread đang chạy (CPU registers, Program Counter) và phục hồi trạng thái của Process/Thread tiếp theo để thực thi.

Vì sao Context Switch làm code chạy chậm?

- Tiêu tốn chu kỳ CPU thực hiện công việc quản lý thay vì chạy business logic.
- Việc đổi không gian bộ nhớ giữa các Process khiến CPU Cache (L1/L2/L3) bị invalidate (Cache Miss tăng cao).
- Tạo quá nhiều Thread (Thread thrashing) sẽ khiến CPU tốn nhiều thời gian Context Switch hơn là xử lý dữ liệu thực tế.


