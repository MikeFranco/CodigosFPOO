const sendError = (res, code, msg, responseCode, log) => { 
  
  if(process.env.DEBUG)
  console.log({ code, msg, log });

  return res
    .status(responseCode ? responseCode : 200)
    .send({
      error: {
        code,
        msg,
        log
      }
    });
}

const sendMySQLError = (res, msg) => sendError(res, 501, 'SQL Error', 500, msg);

const sendSuccess = (res, msg) => 
    res
      .send({
        success: msg
      });

module.exports = { sendError, sendMySQLError, sendSuccess };