# HTTP vs HTTPS

## 1. Bảng so sánh tổng quan

| Tiêu chí | HTTP (Hypertext Transfer Protocol) | HTTPS (HTTP Secure) |
| :--- | :--- | :--- |
| **Cổng mặc định (Port)** | 80 | 443 |
| **Bảo mật** | Plaintext (không mã hóa) | Encrypted (Mã hóa qua TLS/SSL) |
| **Rủi ro** | Dễ bị Eavesdropping, Man-in-the-middle (MITM) | Chống nghe lén và sửa đổi dữ liệu |
| **Chứng chỉ** | Không yêu cầu | Cần SSL/TLS Certificate từ CA |

---

## 2. TLS/SSL Handshake (Cách HTTPS thiết lập mã hóa)

Trước khi truyền dữ liệu HTTP, HTTPS thực hiện TLS Handshake để trao đổi khóa mã hóa:

1. **Client Hello:** Client gửi các phiên bản TLS hỗ trợ và danh sách các thuật toán mã hóa (Cipher Suites).
2. **Server Hello & Certificate:** Server chọn phiên bản TLS, gửi lại SSL Certificate (chứa **Public Key**) do Tổ chức chứng thực (CA) cấp.
3. **Authentication:** Client xác minh Certificate với danh sách CA tin cậy lưu sẵn trong OS.
4. **Key Exchange (Session Key):** 
   - Client tạo một **Symmetric Key** (Khóa đối xứng) ngẫu nhiên.
   - Client dùng **Public Key** của Server để mã hóa Session Key này và gửi cho Server.
5. **Decryption:** Server dùng **Private Key** của mình để giải mã lấy Session Key.
6. **Encrypted Communication:** Từ thời điểm này, mọi dữ liệu HTTP truyền qua lại đều được mã hóa bằng **Session Key (Khóa đối xứng)** để tối ưu tốc độ.

**Key takeaway:** HTTPS kết hợp Mã hóa bất đối xứng (Public/Private Key) để trao đổi khóa an toàn, sau đó dùng Mã hóa đối xứng (Session Key) để truyền dữ liệu thực tế.
