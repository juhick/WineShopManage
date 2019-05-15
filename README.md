## 酒店管理系统

### 1. 员工调动管理

- [x] 员工号输入与查询
- [ ] 查询信息返回并显示
- [ ] 修改信息
- [ ] 更新数据库里的信息

####  报表

```mysql
CREATE TABLE emp_job(
eno NUMBER(4) CONSTRAINTS empj_eno_pk PRIMARY KEY,
ename VARCHAR2(20) CONSTRAINTS empj_ename_nn NOT NULL,
job VARCHAR2(18) CONSTRAINTS empj_job_nn NOT NULL,
dept VARCHAR2(18) CONSTRAINTS empj_dept_nn NOT NULL,
jobinfo VARCHAR2(100) CONSTRAINTS empj_jobinfo_nn NOT NULL,
jobenv VARCHAR2(100) CONSTRAINTS empj_jobenv_nn NOT NULL,
jobtime VARCHAR2(20) CONSTRAINTS empj_jobtime_nn NOT NULL
)
```

#### 单据

```mysql
create table emp_otherinfo(
eno number(4) constraint empoi_eno_pk primary key,
ename varchar2(20) constraint empoi_ename_nn not null,
job varchar2(18) constraint empoi_job_nn not null,
mgr number(4) constraint empoi_mgr_nn not null,
hiredate date constraint empoi_hiredate_nn not null,
sal number(7,2) constraint empoi_sal_nn not null constraint empoi_ename_ck check(sal > 0),
comm number(7,2) constraint empoi_comm_ck check(comm > 0),
dept varchar2(18) constraint empoi_dept_nn not null,
esex char(2) constraint empoi_esex_nn not null,
eage number(3) constraint empoi_eage_nn not null,
constraint empoi_esex_ck check(esex in ('男','女')),
constraint empoi_eage_ck check(eage >= 20 and eage <= 60)
)
```

### 2. 员工考勤管理

* [ ] 输入信息类别
* [ ] 输入员工号
* [ ] 记录信息
* [ ] 更新数据库里的信息
* [ ] 统计考勤信息并返回

####  报表

```mysql
CREATE TABLE attendinfo_count(
eno NUMBER(4) CONSTRAINTS aocount_eno_pk PRIMARY KEY,
ename VARCHAR2(20) CONSTRAINTS aocount_ename_nn NOT NULL,
normaltimes NUMBER(4) CONSTRAINTS aocount_normaltimes_nn NOT NULL,
overtimes NUMBER(4) CONSTRAINTS aocount_overtimes_nn NOT NULL,
latetimes NUMBER(4) CONSTRAINTS aocount_latetimes_nn NOT NULL,
earlytimes NUMBER(4) CONSTRAINTS aocount_earlytimes_nn NOT NULL,
leavetimes NUMBER(4) CONSTRAINTS aocount_leavetimes_nn NOT NULL,
absenttimes NUMBER(4) CONSTRAINTS aocount_absenttimes_nn NOT NULL
)
```

#### 单据

```mysql
create table emp_attendinfo(
eno number(4) constraint empai_eno_pk primary key,
ename varchar2(20) constraint empai_ename_nn not null,
attendcode char(4) constraint empai_attendcode_nn not null,
attenddate date constraint empai_attenddate_nn not null,
constraint empai_attendcode_ck check(attendcode in ('正常','加班','迟到','早退','旷工','请假'))
)
```

### 3. 财务统计归档

* [ ] 输入信息类别
* [ ] 输入财务信息
* [ ] 记录信息
* [ ] 更新数据库里的信息
* [ ] 统计相关信息并返回

####  报表

```mysql
CREATE TABLE financial_countinfo(
deptname VARCHAR2(18) CONSTRAINTS ficount_deptname_pk PRIMARY KEY,
samount NUMBER(9,2) CONSTRAINTS ficount_samount_nn NOT NULL,
iamount NUMBER(9,2) CONSTRAINTS ficount_iamount_nn NOT NULL,
profit NUMBER(9,2) CONSTRAINTS ficount_profit_nn NOT NULL,
stadata DATE CONSTRAINTS ficount_stadata_nn NOT NULL
)
```

#### 单据

```mysql
CREATE TABLE financialinfo(
pno NUMBER(6) CONSTRAINTS fninfo_pno_pk PRIMARY KEY,
pname VARCHAR2(40) CONSTRAINTS fninfo_pname_nn NOT NULL,
pdept VARCHAR2(20) CONSTRAINTS fninfo_pdept_nn NOT NULL,
money NUMBER(9,2) CONSTRAINTS fninfo_money_nn NOT NULL,
subtime DATE CONSTRAINTS fninfo_subtime_nn NOT NULL,
pusage VARCHAR2(200) CONSTRAINTS fninfo_pusage_nn NOT NULL,
pmgr VARCHAR2(20) CONSTRAINTS fninfo_pmgr_nn NOT NULL,
type CHAR(4) CONSTRAINTS fninfo_type_nn NOT NULL,
CONSTRAINTS fninfo_money_ck CHECK(money > 0),
CONSTRAINTS fninfo_type_ck CHECK(type IN ('收入','支出'))
)
```