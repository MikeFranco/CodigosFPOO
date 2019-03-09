
const mysql = require('mysql');

const getWorkingDatabase = () => process.env.MYSQL_DATABASE || 'dbreal';

const getMySqlUser = () => process.env.MYSQL_USER || 'root';

const getMySqlPassword = () => process.env.MYSQL_PASSWORD || 'root';

const getMySqlHost = () => process.env.MYSQL_HOST || 'localhost';

const con = mysql.createPool({
  connectionLimit: 10,
  host: getMySqlHost(),
  user: getMySqlUser(),
  password: getMySqlPassword(),
  database: getWorkingDatabase()
});

module.exports = con;