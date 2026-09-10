# Vòng đời Request - Response (Request-Response Lifecycle)

Điều gì thực sự xảy ra khi bạn gõ `https://github.com` vào thanh địa chỉ trình duyệt và nhấn **Enter**?

---

## Luồng xử lý end-to-end

```text
[Browser] ──(1. DNS Lookup)──> [IP Address]
   │
   ├──(2. TCP 3-Way Handshake)──> Thiết lập kết nối Socket (Port 443)
   │
   ├──(3. TLS Handshake)────────> Thỏa thuận khóa mã hóa SSL/TLS
   │
   ├──(4. Send HTTP Request)────> GET / HTTP/1.1
   │
   ├──[Server/Load Balancer] ───> Nginx/HAProxy phân phối request vào App Server
   │                                  │
   │                                  ├── Kiểm tra Auth / Middleware
   │                                  ├── Xử lý Business Logic
   │                                  └── Truy vấn Database (SQL/NoSQL)
   │
   ├──(5. Receive HTTP Response)─< HTTP/1.1 200 OK (HTML Payload)
   │
   └──(6. Browser Rendering)────> Parse HTML ──> Build DOM/CSSOM ──> Render Page
```

---

## Cơ cấu một HTTP Request & Response

HTTP Request

```text
GET /users/123 HTTP/1.1
Host: api.example.com
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64)
Accept: application/json
Authorization: Bearer eyJhbGciOi...

{"query": "active"}
```

- Request Line: HTTP Method (`GET`, `POST`, `PUT`, `DELETE`), Request URI, HTTP Version.
- Headers: Metadata (`Host`, `User-Agent`, `Content-Type`, `Authorization`).
- Body: Dữ liệu gửi lên (Thường dùng cho `POST`/`PUT`).

HTTP Response

```text
HTTP/1.1 200 OK
Date: Thu, 10 Sep 2026 22:30:00 GMT
Server: nginx/1.18.0
Content-Type: application/json; charset=utf-8
Content-Length: 54

{
  "id": 123,
  "name": "Minh Quan",
  "status": "active"
}
```

- Status Line: HTTP Version, Status Code, Reason Phrase.
- Headers: Metadata từ Server (`Content-Type`, `Set-Cookie`, `Cache-Control`).
- Body: Nội dung phản hồi (HTML, JSON, Image,...).

---

## Một số HTTP Status Codes quan trọng

- 1xx (Informational): Đã nhận request, đang tiếp tục xử lý (Ví dụ: `101 Switching Protocols`).
- 2xx (Success): Xử lý thành công (`200 OK`, `201 Created`, `204 No Content`).
- 3xx (Redirection): Cần thực hiện hành vi bổ sung (`301 Moved Permanently`, `302 Found`, `304 Not Modified`).
- 4xx (Client Error): Lỗi do phía Client (`400 Bad Request`, `401 Unauthorized`, `403 Forbidden`, `404 Not Found`).
- 5xx (Server Error): Lỗi hệ thống phía Server (`500 Internal Server Error`, `502 Bad Gateway`, `503 Service Unavailable`).
