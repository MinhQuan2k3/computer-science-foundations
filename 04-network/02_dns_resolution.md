# Cơ chế phân giải tên miền (DNS Resolution)

**DNS (Domain Name System)** đóng vai trò như "danh bạ của Internet", biến tên miền dạng con người đọc được (`google.com`) thành địa chỉ IP mà máy tính hiểu được (`142.250.190.46`).

## Các thành phần trong hệ thống DNS

- **DNS Client (Resolver):** Thường là OS hoặc Router, nhận yêu cầu phân giải IP từ trình duyệt.
- **Root Nameserver (`.`):** Tầng đỉnh của hệ thống DNS, chỉ hướng tới TLD Server.
- **TLD Nameserver (`.com`, `.net`, `.vn`):** Quản lý các tên miền theo phần mở rộng.
- **Authoritative Nameserver:** Server chứa bản ghi DNS chính thức của tên miền cụ thể (ví dụ: DNS của Cloudflare, Route53).

---

## Quy trình phân giải DNS (DNS Lookup Steps)

Khi bạn gõ `https://example.com` trên trình duyệt:

```text
[Browser] 
   │ 
   ├── 1. Check Browser Cache & OS Cache ──(Tìm thấy IP)──> Trả về IP ngay
   │
   └── 2. Gửi Query tới Recursive DNS Resolver (thường là ISP hoặc 8.8.8.8)
              │
              ├── 3. Hỏi Root Server (.) --------------> Trả về IP của TLD Server (.com)
              ├── 4. Hỏi TLD Server (.com) ------------> Trả về IP của Authoritative Server
              ├── 5. Hỏi Authoritative Server ---------> Trả về IP chuẩn: 93.184.216.34
              │
              └── 6. Cache lại IP & Trả về cho Trình duyệt
```
---
## Các bản ghi DNS căn bản (DNS Record Types)

- A Record: Ánh xạ Tên miền --> Địa chỉ IPv4.
- AAAA Record: Ánh xạ Tên miền --> Địa chỉ IPv6.
- CNAME (Canonical Name): Trỏ một tên miền alias về một tên miền khác (ví dụ: `[www.example.com](https://www.example.com`) --> `example.com`).
- MX Record (Mail Exchange): Chỉ định Server xử lý email cho tên miền.
- TXT Record: Lưu dữ liệu dạng văn bản (dùng xác minh chủ sở hữu tên miền, SPF/DKIM chống spam).
