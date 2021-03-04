-- Put only sql structure in this file (create table if exists, delete table, alter table etc...).
-- If you don't use this database, then delete this file.
create table sponsorship
(
    godfather  int      not null,
    nephew int      not null,
    begin             datetime null,
    primary key (godfather, nephew)
);
