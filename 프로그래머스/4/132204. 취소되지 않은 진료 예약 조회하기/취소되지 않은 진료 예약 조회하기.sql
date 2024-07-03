-- 코드를 입력하세요
SELECT a.APNT_NO,p.PT_NAME,p.PT_NO,a.MCDP_CD,d.DR_NAME,a.APNT_YMD from appointment as a
join doctor as d on d.dr_id = a.mddr_id
join patient as p on p.pt_no = a.pt_no
where apnt_cncl_yn = 'N' and date_format(apnt_ymd,'%Y-%m-%d') = '2022-04-13' and a.mcdp_cd = "CS"
order by a.apnt_ymd asc;
