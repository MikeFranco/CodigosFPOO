const queries = require('./me-queries');
const con = require('./db-connection');
const { sendMySQLError, sendError, sendSuccess } = require('./response-mixins');

const getUserName = (req, res) => {

  const token = req.decodedToken;
  const userId = token.id;

  con.query(queries.getUserName(userId), (err, queryResult) => {
      //agregar el aun como atributo
    return err
      ? sendMySQLError(res, err.sqlMessage)
      : queryResult.length > 0
      ? sendSuccess(res, {
          name: queryResult[0].name,
          balance: queryResult[0].balance,
          userId: queryResult[0].id,
          iat: token.iat,
          //aum: 
        })
      : sendError(res, 455, 'No User Found');

  });

};

const aum = (req,res) =>{

  const token = req.decodedToken;
  const userId = token.id;

  con.query(queries.aum(userId), (err, queryResult) => {
    return err
    ? sendMySQLError(res, err.sqlMessage)
    : queryResult.length >0
    ? sendSuccess(res, queryResult)
    : sendError(res, 455, 'No User Found')
  })
}

const updateBalance = (req, res) => {

  const token = req.decodedToken;
  const userId = token.id
  const { newBalance } = req.body;

  con.query(queries.updateBalance(newBalance, userId), (err, queryResult) => {

    return err
    ? sendMySQLError(res, err.sqlMessage)
    : sendSuccess(res, newBalance);

  })

}

module.exports = {
  getUserName,
  updateBalance,
  aum
};