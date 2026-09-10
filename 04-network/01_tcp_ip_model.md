# Mô hình TCP/IP (TCP/IP Model)

Mô hình TCP/IP là tập hợp các giao thức truyền thông dùng để kết nối các thiết bị mạng trên Internet.

## 1. Các tầng trong mô hình TCP/IP (4 Tầng)

| Tầng (Layer) | Chức năng chính | Giao thức tiêu biểu | Đơn vị dữ liệu (PDU) |
| :--- | :--- | :--- | :--- |
| **Application** | Giao tiếp trực tiếp với ứng dụng người dùng | HTTP, HTTPS, DNS, FTP, SMTP, SSH | Data / Payload |
| **Transport** | Truyền tải dữ liệu end-to-end giữa 2 tiến trình (process) | TCP, UDP | Segment (TCP) / Datagram (UDP) |
| **Internet** | Định tuyến (routing) gói tin qua các mạng khác nhau | IP (IPv4, IPv6), ICMP, ARP | Packet |
| **Network Access** | Truyền dữ liệu vật lý giữa các thiết bị trong cùng một mạng LAN | Ethernet, Wi-Fi (802.11) | Frame |

---

## 2. So sánh TCP vs UDP

| Tiêu chí | TCP (Transmission Control Protocol) | UDP (User Datagram Protocol) |
| :--- | :--- | :--- |
| **Kết nối** | Connection-oriented (Cần bắt tay 3 bước) | Connectionless (Gửi không cần thiết lập kết nối) |
| **Độ tin cậy** | Cao (Có ACK, Retransmission khi mất gói) | Thấp (Không kiểm tra mất gói, không gửi lại) |
| **Thứ tự dữ liệu** | Đảm bảo đúng thứ tự gửi | Không đảm bảo thứ tự |
| **Tốc độ** | Chậm hơn (do tốn overhead quản lý) | Nhanh, overhead cực thấp |
| **Use Case** | Web (HTTP/HTTPS), Email, File transfer (FTP) | Streaming, Game online, VoIP, DNS Lookup |

---

## 3. Cơ chế Bắt tay 3 bước của TCP (TCP 3-Way Handshake)

Được sử dụng để khởi tạo kết nối tin cậy giữa Client và Server trước khi truyền dữ liệu.

```text
Client                                  Server
  |                                       |
  | -------- SYN (Seq = x) -------------> |  (Client muốn kết nối)
  |                                       |
  | <--- SYN-ACK (Seq = y, Ack = x + 1) - |  (Server đồng ý và phản hồi)
  |                                       |
  | -------- ACK (Ack = y + 1) ---------> |  (Client xác nhận -> Kết nối ESTABLISHED)
```

- SYN: Client gửi gói tin SYN mang số thứ tự khởi tạo (`Seq = x`).
- SYN-ACK: Server nhận SYN, phản hồi bằng SYN-ACK (`Ack = x + 1`, `Seq = y`).
- ACK: Client xác nhận lại với Server (`Ack = y + 1`). Kết nối chính thức được tạo.
