
-- SQL 1
select * from user_profile;

-- SQL 9
select device_id, gender, age, university  from user_profile where university != '复旦大学';

-- SQL 10
-- tip: 查询NULL时，不能使用比较运算符(=或者< >)，需要使用IS NULL运算符或者IS NOT NULL运算符。
select device_id, gender, age, university from user_profile where age is NOT NULL;

-- SQL 11
select device_id, gender, age, university, gpa from user_profile where gender='male' and gpa > 3.5;

-- SQL 12
select device_id, gender, age, university, gpa from user_profile where university = '北京大学' or gpa > 3.7;

-- SQL 13
select device_id, gender, age, university, gpa from user_profile where university IN ('北京大学', '复旦大学', '山东大学');

-- SQL 14
select device_id, gender, age, university, gpa from user_profile where (university = '山东大学' and gpa > 3.5) or (university = '复旦大学' and gpa > 3.8);

-- SQL 15
select device_id, age, university from user_profile where university LIKE '%北京%';

-- SQL 16
select max(gpa) as gpa from user_profile;

--SQL 17
select count(gender) as male_num, round(avg(gpa), 1) as avg_gpa from user_profile where gender = 'male';

-- SQL 18
-- 分组练习
select gender,
       university,
       count(id)                        as user_num,
       round(avg(active_days_within_30), 1) as avg_active_day,
       round(avg(question_cnt), 1)          as avg_question_cnt
from user_profile
group by university, gender;

-- SQL 19
