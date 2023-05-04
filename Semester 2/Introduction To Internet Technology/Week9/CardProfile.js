const CardProfile = ({ name, email, foto, phone }) => {
	return (
		<div className="CardProfile">
			<div className="Card-Content">
				<div className="Data">
					<div className="nama">
						<h1>{name}</h1>
					</div>
					<div className="phone">
						<p>{phone}</p>
					</div>
					<div className="email">
						<p>{email}</p>
					</div>
				</div>
				<div className="img">
					<div className="avatar">
						<img src={foto} alt="avatar" />
					</div>
				</div>
			</div>
		</div>
	);
};

export default CardProfile;
