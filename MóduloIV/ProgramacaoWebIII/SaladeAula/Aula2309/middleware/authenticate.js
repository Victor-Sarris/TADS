import jwt from 'jsonwebtoken';
const secret = process.env.SECRET_JWT;

const authenticate = (req, res, next)=>{
    console.log(req);
    const token = res.headers.authorization;
}

export default authenticate;