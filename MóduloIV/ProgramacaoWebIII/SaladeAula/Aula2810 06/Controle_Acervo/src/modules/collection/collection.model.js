import { DataTypes } from "sequelize";
import conectDB from "../../config/db.js";
import User from "../user/user.model.js"

const sequelize = await conectDB();
const Collection = sequelize.define("Collections",{
    id: {type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true, allowNull: false},
    name: {type: DataTypes.STRING, allowNull: false},
    description: {type: DataTypes.STRING, allowNull: false},
    type: {type: DataTypes.STRING, allowNull: false},
    value: {type: DataTypes.FLOAT, allowNull: true},
    ownerId: {type: DataTypes.INTEGER, allowNull: false, references: {model: User, key: 'id'}},
});

User.belongsToMany(Object, {through: Collection})

Collection.belongsTo(User)
User.hasMany(Collection)

await Collection.sync();
export default Collection;