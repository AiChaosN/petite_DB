// ---- petiteDB dialect example ----

// 定义方言
module attributes {dialect = "petite"} {
  // scan 操作
  %table = petite.scan "table_name" : !petite.table

  // project 操作，选择特定列
  %columns = petite.project %table ["column1", "column2"] : (!petite.table) -> !petite.table

  // join 操作，将两个表连接起来
  %joined_table = petite.join %table, %another_table ["column1", "column2"] : (!petite.table, !petite.table) -> !petite.table

  // select 操作，选择符合条件的行
  %selected_rows = petite.select %table ["column1 = 'value'"] : (!petite.table) -> !petite.table
}
