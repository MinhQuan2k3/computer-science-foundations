USE AnimationStudioDB;
GO

IF OBJECT_ID('MerchandiseStock', 'U') IS NOT NULL DROP TABLE MerchandiseStock;

CREATE TABLE MerchandiseStock (
    ItemID INT PRIMARY KEY IDENTITY(1,1),
    ItemName NVARCHAR(100),
    Quantity INT
);

INSERT INTO MerchandiseStock (ItemName, Quantity) VALUES 
(N'Totoro Plush Toy', 10),
(N'No-Face Figurine', 5);
GO

-- Ví dụ Transaction mua hàng có kiểm soát Rollback
BEGIN TRANSACTION;

BEGIN TRY
    -- 1. Trừ kho Totoro Plush Toy
    UPDATE MerchandiseStock 
    SET Quantity = Quantity - 2 
    WHERE ItemName = N'Totoro Plush Toy';

    -- Đặt Savepoint sau bước 1
    SAVE TRANSACTION SaveAfterTotoro;

    -- 2. Thử trừ kho sản phẩm với số lượng âm (kịch bản lỗi)
    UPDATE MerchandiseStock 
    SET Quantity = Quantity - 100 
    WHERE ItemName = N'No-Face Figurine';

    -- Kiểm tra logic: Không cho phép Quantity < 0
    IF EXISTS (SELECT 1 FROM MerchandiseStock WHERE Quantity < 0)
    BEGIN
        RAISERROR(N'Insufficient Stock', 16, 1);
    END

    COMMIT TRANSACTION;
    PRINT N'Transaction Successful';
END TRY
BEGIN CATCH
    -- Rollback toàn bộ hoặc về Savepoint tùy yêu cầu
    ROLLBACK TRANSACTION;
    PRINT N'Transaction Failed: ' + ERROR_MESSAGE();
END CATCH;

-- Kiểm tra lại dữ liệu (vẫn giữ nguyên 10 và 5)
SELECT * FROM MerchandiseStock;
