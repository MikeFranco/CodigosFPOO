// Librerías
const app = require('express')();
const auth = require('./src/auth/jwt-auth');
const bodyParser = require('body-parser');
const upload = require('express-fileupload');

// Rutas
const me = require('./src/me/me');

const port = process.env.PORT || 5000;

app.use(function(req, res, next) {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    next();
  });

app.use(bodyParser.json());

app.use(upload({
  limits: {
    fileSize: 20 * 1024 * 1024
  },
  abortOnLimit: true
}));

app.get('/', (req, res) => res.send('Nothing to see here 👀 - Axend'));

// Paso donde ser verifica si en el header viene el token
// En caso de no venir, no puede acceder a ninguna de las siguientes rutas
app.use(auth.verifyJwt);

app.route('/me')
  .get(me.getUserName)
  .patch(me.updateBalance)
  .delete(me.aum);

app.listen(port, () => console.log(`Corriendo Axend Backend en el puerto: ${port}`));

module.exports = { app };
