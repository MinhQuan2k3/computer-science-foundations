# Database Foundations

Tổng hợp các kiến thức cốt lõi về Cơ sở dữ liệu quan hệ (RDBMS), sử dụng chủ đề **Phim hoạt hình (Animation Studio)** và kiểm thử trực tiếp trên **SQL Server / SSMS**.

## Cấu trúc

- `sql/`: Các truy vấn SQL căn bản, các dạng `JOIN` (Inner, Left, Right, Full Outer) và gom nhóm `GROUP BY / HAVING`.
- `normalization/`: Các bước chuẩn hóa dữ liệu từ Unnormalized (UNF) lên 1NF, 2NF, 3NF để giảm thiểu dư thừa dữ liệu và lỗi bất thường (Anomalies).
- `index/`: Khái niệm Clustered Index, Non-Clustered Index và cách tối ưu hiệu năng truy vấn.
- `transaction/`: Điều khiển luồng giao dịch với `BEGIN TRANSACTION`, `COMMIT`, `ROLLBACK` và `SAVEPOINT`.
- `acid/`: Minh họa 4 thuộc tính nguyên tử của RDBMS: **A**tomicity, **C**onsistency, **I**solation, **D**urability.

## RDBMS vs NoSQL

| Tiêu chí | SQL (Relational) | NoSQL (Non-Relational) |
| :--- | :--- | :--- |
| **Data Structure** | Bảng (Tables), hàng & cột rõ ràng | Document (JSON), Key-Value, Graph, Column-family |
| **Schema** | Cố định (Rigid Schema) | Linh hoạt (Dynamic Schema) |
| **ACID vs BASE** | Tuân thủ nghiêm ngặt ACID | Ưu tiên BASE (Basically Available, Soft-state, Eventual consistency) |
| **Scaling** | Mở rộng theo chiều dọc (Vertical Scaling - tăng RAM/CPU) | Mở rộng theo chiều ngang (Horizontal Scaling - thêm máy chủ) |
| **Khi nào chọn?** | Hệ thống tài chính, giao dịch, dữ liệu quan hệ phức tạp | Big Data, dữ liệu thời gian thực, hệ thống lưu trữ không cấu trúc |
