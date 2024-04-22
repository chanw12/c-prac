select d.DEPT_ID,d.DEPT_NAME_EN,ROUND(AVG(e.SAL),0) as AVG_SAL from hr_department as d
join hr_employees as e
on d.dept_id = e.dept_id
group by d.dept_id
order by AVG_SAL desc
