SELECT 
    CAR_ID,
    CASE 
        WHEN SUM(CASE WHEN DATE_FORMAT(START_DATE,'%Y-%m-%d') <= '2022-10-16' AND '2022-10-16' <= DATE_FORMAT(END_DATE,'%Y-%m-%d') THEN 1 ELSE 0 END) > 0 THEN '대여중' 
        ELSE '대여 가능' 
    END AS AVAILABILITY
FROM 
    car_rental_company_rental_history
GROUP BY 
    CAR_ID
ORDER BY 
    CAR_ID DESC;
