USE AnimationStudioDB;
GO

/*
  ======================================================
  THUỘC TÍNH ACID TRONG RDBMS
  1. Atomicity (Tính nguyên tố): Tất cả hoặc không gì cả.
  2. Consistency (Tính nhất quán): Ràng buộc dữ liệu được đảm bảo trước & sau Transaction.
  3. Isolation (Tính cô lập): Các giao dịch song song không can thiệp lẫn nhau.
  4. Durability (Tính bền vững): Dữ liệu sau Commit sẽ tồn tại vĩnh viễn dù crash hệ thống.
  ======================================================
*/

IF OBJECT_ID('StudioVault', 'U') IS NOT NULL DROP TABLE StudioVault;

CREATE TABLE StudioVault (
    StudioName NVARCHAR(50) PRIMARY KEY,
    BudgetMillions DECIMAL(10,2) CHECK (BudgetMillions >= 0) -- Đảm bảo Consistency
);

INSERT INTO StudioVault VALUES (N'Ghibli', 50.00), (N'Pixar', 100.00);
GO

-- Demonstration: Atomicity & Consistency
BEGIN TRANSACTION;

UPDATE StudioVault SET BudgetMillions = BudgetMillions - 20.00 WHERE StudioName = N'Ghibli';
-- Dòng dưới đây sẽ vi phạm CHECK constraint (Budget < 0) -> Gây lỗi Consistency
UPDATE StudioVault SET BudgetMillions = BudgetMillions - 200.00 WHERE StudioName = N'Pixar';

IF @@ERROR <> 0
BEGIN
    -- Atomicity khôi phục trạng thái ban đầu của Ghibli
    ROLLBACK TRANSACTION;
    PRINT N'ACID Violation: Rollback transaction.';
END
ELSE
BEGIN
    COMMIT TRANSACTION;
END;

-- Demonstration: Isolation Level (Ví dụ cấu hình mức cô lập)
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRANSACTION;
    SELECT * FROM StudioVault WHERE StudioName = N'Ghibli';
COMMIT TRANSACTION;
